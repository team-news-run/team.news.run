TARGET = pc_test

CXX = g++
CXXFLAGS = -std=c++14 -W -Wall
LFLAGS = -I.

SRCS = py_crawler.cpp pc_test.cpp

$(TARGET) :
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LFLAGS)

clean :
	rm -f $(TARGET)
