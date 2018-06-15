#ifndef __NEWS_CONTENTS_H__
#define __NEWS_CONTENTS_H__

#include <map>
#include <vector>
#include <string>

class NewsContents {
    public:
    explicit NewsContents();
    virtual ~NewsContents();

    std::vector<std::string> contents(const std::string& topic);

    private:
    std::map<std::string, std::string> table;

    void buildTable();
    const std::string& topicUrl(const std::string& topic);

};

#endif
