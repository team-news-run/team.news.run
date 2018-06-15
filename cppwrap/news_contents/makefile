TARGET = nc_test

CXX = g++
CXXFLAGS = -std=c++14 -W -Wall
LFLAGS = -I.

SRCS = news_contents.cpp py_crawler.cpp nc_test.cpp

$(TARGET) :
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LFLAGS)

clean :
	rm -f $(TARGET)
