#include <iostream>
#include <vector>
#include <string>

#include "news_contents.h"

int main(int argc, char* argv[]) {
    try {
        // NewsContents 객체 생성
        NewsContents nc;
        std::string topic {"economic"};
        // topic을 요청하면 요약된 news 기사를 얻는다.
        std::vector<std::string> contents = nc.contents(topic);

        std::cout << "News Topic : " << topic << std::endl;
        int cnt {1};
        for(const auto& text : contents) {
            std::cout << "nc_test::" << cnt++ << " text : " << std::endl;
            std::cout << text << std::endl;
        }
    }
    catch (const char* msg) {
        std::cout << argv[0] << "::Exception : ";
        std::cout << msg << std::endl;
        return -1;
    }
}
