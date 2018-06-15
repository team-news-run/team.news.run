TARGET = get_news

CXX = g++
CXXFLAGS = -std=c++14 -W -Wall
LFLAGS = -I.

SRCS = news_contents.cpp py_crawler.cpp main.cpp

OUTPUT_FILE_FORMAT = news_?.txt

$(TARGET) :
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LFLAGS)

clean :
	rm -f $(TARGET) $(OUTPUT_FILE_FORMAT)
