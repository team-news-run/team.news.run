#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

#include "news_contents.h"
#include "py_crawler.h"

NewsContents::NewsContents() {
    buildTable();
}

NewsContents::~NewsContents() {
}

std::vector<std::string> NewsContents::contents(const std::string& topic) {
    if(table.find(topic) == table.end()) {
        throw "NewsContents::No such topic in this table.";
    }

    std::string topicUrl = table[topic];
    PyCrawler pc(topicUrl);
    std::vector<std::string> newsContents;

    std::vector<std::string> contentsList = pc.getContentsFiles();
    for(const auto& contentsFile : contentsList) {
        std::ifstream fst(contentsFile);
        std::string text((std::istreambuf_iterator<char>(fst)), \
                          std::istreambuf_iterator<char>());
        newsContents.push_back(text);
    }

    return newsContents;
}

namespace topics {
    const std::string society {"society"};
    const std::string economic {"economic"};
    const std::string politics {"politics"};
    const std::string foreign {"foreign"};
    const std::string digital {"digital"};

    const std::string url_base {"http://media.daum.net/"};
    const std::string url_suffix {"/"};
}

void NewsContents::buildTable() {
    table.insert(std::make_pair(topics::society, topicUrl(topics::society)));
    table.insert(std::make_pair(topics::economic, topicUrl(topics::economic)));
    table.insert(std::make_pair(topics::politics, topicUrl(topics::politics)));
    table.insert(std::make_pair(topics::foreign, topicUrl(topics::foreign)));
    table.insert(std::make_pair(topics::digital, topicUrl(topics::digital)));
}

const std::string& NewsContents::topicUrl(const std::string& topic) {
    return std::string {topics::url_base + topic + topics::url_suffix};
}


