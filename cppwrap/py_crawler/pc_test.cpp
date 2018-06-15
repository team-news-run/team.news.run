#include <iostream>
#include <string>
#include <vector>

#include "py_crawler.h"

int main(int argc, char* argv[]) {
    if(argc != 1) {
        std::cout << "Too many arguments." << std::endl;
        return -1;
    }

    std::vector<std::string> contentsFiles {};
    try {
        PyCrawler pc;
        contentsFiles = pc.getContentsFiles();
        std::cout << "get contents files." << std::endl;
    }
    catch(const char* msg) {
        std::cout << argv[0] << " :: Exception : " << msg << std::endl;
        return -1;
    }
    
    std::cout << "contents file list : " << std::endl;
    for(const auto& fileName : contentsFiles) {
        std::cout << fileName << std::endl;
    }
    
    std::cout << "End of " << argv[0] << std::endl;
    return 0;
}
