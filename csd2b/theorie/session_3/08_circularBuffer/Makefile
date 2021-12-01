CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= melody.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CFLAGS)

clean:
	rm -f $(TARGET) *.o
