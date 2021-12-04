CXX= g++
CFLAGS = -Wall -std=c++1z
LDFLAGS= 
SOURCE= main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CFLAGS)

clean:
	rm -f $(TARGET) *.o
