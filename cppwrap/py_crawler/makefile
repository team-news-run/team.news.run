TARGET = pc_test

CXX = g++
CXXFLAGS = -std=c++11 -W -Wall
LFLAGS = -I.

SRCS = py_crawler.cpp pc_test.cpp

OUTPUT_TEXT_BASE = output

$(TARGET) :
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LFLAGS)

clean :
	rm -f $(TARGET) $(OUTPUT_TEXT_BASE)*.txt
