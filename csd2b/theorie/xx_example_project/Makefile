CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++14
LDFLAGS= -ljack
SOURCE= writeToFile.o generator.o oscillator.o sine.o saw.o jack_module.o main.o
all: example

example : $(SOURCE)
	$(CC) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
	rm -f output.csv
