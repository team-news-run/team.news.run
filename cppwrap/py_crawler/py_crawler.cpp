// C++ dependency
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "py_crawler.h"

// Unix dependency
#include <unistd.h>
#include <sys/types.h>  // pid_t fork()
#include <sys/wait.h>   // pid_t wait(int* stat_loc)

// C dependency
#include <stdlib.h>

PyCrawler::PyCrawler(const std::string& url, const std::string& pyVer, \
                     const std::string& pyScript) \
   : urlForRequest{url}, pyInterpreter{pyVer}, scriptFile{pyScript} {

    execPyScript();
    checkContentsExist();
}

PyCrawler::~PyCrawler() {
}

std::vector<std::string> PyCrawler::getContentsFiles() {
    return contentsFiles;
}

bool PyCrawler::isFileExist(const std::string& file) {
    std::fstream fst(file);
    return (!fst) ? false : true;
}

void PyCrawler::checkContentsExist() {
    // crawled contents file parameters
    const std::string nameBase {"output"};  // file name base
    const std::string suffix {".txt"};      // file extension
    const int maxnum {10};   // maximum a number of contents files

    for(int num = 0; num < maxnum; ++num) {
        std::string file {nameBase + std::to_string(num) + suffix};
        if(isFileExist(file)) {
            contentsFiles.push_back(file);
        }
    }
}

void PyCrawler::execPyScript() {
    pid_t pid = fork();
    if(pid < 0) {
        throw "Failed to fork()";
    }
    else if(pid == 0) { // Child process
        std::string pyArgs = scriptFile + " " + urlForRequest;
        const char* prog = pyInterpreter.c_str();
        const char* args = pyArgs.c_str();
        int res = execlp(prog, prog, args, NULL); 
        if(res < 0) {
            exit(-1);
        }
        exit(0);
    }
    else {  // Parent process
        int stat_val;
        wait(&stat_val);
        if(WIFEXITED(stat_val) && !WEXITSTATUS(stat_val)) {
            return;
        }
        else {  // Child process가 정상종료 되지 않을 경우 예외 발생
            throw "Failed to execute py_script";
        }
    }
}

