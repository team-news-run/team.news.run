#include <iostream>

#include "py_crawler.h"

int main(int argc, char* argv[]) {
    if(argc != 1) {
        std::cout << "Too many arguments." << std::endl;
        return -1;
    }

    try {
        PyCrawler pc;
    }
    catch(const char* msg) {
        std::cout << argv[0] << " :: Exception : " << msg << std::endl;
        return -1;
    }
    
    return 0;
}
