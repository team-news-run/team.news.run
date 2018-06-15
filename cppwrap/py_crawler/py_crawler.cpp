// C++ dependency
#include <vector>
#include <iostream>

#include "py_crawler.h"

// Unix dependency
#include <unistd.h>
#include <sys/types.h>  // pid_t fork()
#include <sys/wait.h>   // pid_t wait(int* stat_loc)

// C dependency
#include <stdlib.h>

PyCrawler::PyCrawler() {
    pyInterpreter = std::string {"python3"};
    scriptFile = std::string{"news_crawler.py"};

    execPyScript();
}

PyCrawler::~PyCrawler() {
}

std::vector<std::string> PyCrawler::getOutFiles() {
    return outFiles;
}

void PyCrawler::execPyScript() {
    pid_t pid = fork();
    if(pid < 0) {
        throw "Failed to fork()";
    }
    else if(pid == 0) {
        const char* prog = pyInterpreter.c_str();
        const char* args = scriptFile.c_str();
        int res = execlp(prog, prog, args, NULL); 
        if(res < 0) {
            exit(-1);
        }
        exit(0);
    }
    else {
        int stat_val;
        wait(&stat_val);
        if(WIFEXITED(stat_val) && !WEXITSTATUS(stat_val)) {
            return;
        }
        else {
            throw "Failed to execute py_script";
        }
    }
}
