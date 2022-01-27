CXX=g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= 
SOURCE= circBuffer.o sine.o oscillator.o writeToFile.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
