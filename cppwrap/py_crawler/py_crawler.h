#ifndef __PY_CRAWLER_H__
#define __PY_CRAWLER_H__

#include <vector>
#include <string>

class PyCrawler {
public:
    PyCrawler();
    virtual ~PyCrawler();

    std::vector<std::string> getContentsFiles();
private:
    void execPyScript();    // python script 실행
    void checkContentsExist();  // crawled contents file이 존재하는지 확인
    bool isFileExist(const std::string&);

    std::string pyInterpreter;
    std::string scriptFile;
    std::vector<std::string> contentsFiles;
};

#endif
