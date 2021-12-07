CXX =g++
CXXFLAGS =-I/usr/local/include -Wall -std=c++11
LDFLAGS=-ljack
SOURCE=jack_module.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
