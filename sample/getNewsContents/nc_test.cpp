#include <iostream>
#include <vector>
#include <string>

#include "news_contents.h"

int main() {
    NewsContents nc;
    std::vector<std::string> contents = nc.contents(std::string{"society"});

    int cnt {1};
    for(const auto& text : contents) {
        std::cout << "nc_test::" << cnt++ << " text : " << std::endl;
        std::cout << text << std::endl;
    }

    return 0;
}
