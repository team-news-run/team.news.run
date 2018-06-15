#ifndef __PY_CRAWLER_H__
#define __PY_CRAWLER_H__

#include <vector>
#include <string>

class PyCrawler {
public:
    PyCrawler();
    virtual ~PyCrawler();

    std::vector<std::string> getOutFiles();
private:
    void execPyScript();

    std::string pyInterpreter;
    std::string scriptFile;
    std::vector<std::string> outFiles;
};

#endif
