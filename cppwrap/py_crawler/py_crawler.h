#ifndef __PY_CRAWLER_H__
#define __PY_CRAWLER_H__

#include <vector>
#include <string>

class PyCrawler {
public:
    explicit PyCrawler(const std::string& url, \
              const std::string& pyVer = std::string {"python3"}, \
              const std::string& pyScript = std::string {"news_crawler.py"});
    virtual ~PyCrawler();

    std::vector<std::string> getContentsFiles();
private:
    void execPyScript();    // Python script 실행
    void checkContentsExist();  // Crawled contents file이 존재하는지 확인
    bool isFileExist(const std::string&);
    
    std::string urlForRequest;  // Crawling 요청할 url
    std::string pyInterpreter;  // Python version 지정
    std::string scriptFile; // Script file name 지정
    std::vector<std::string> contentsFiles;
};

#endif
