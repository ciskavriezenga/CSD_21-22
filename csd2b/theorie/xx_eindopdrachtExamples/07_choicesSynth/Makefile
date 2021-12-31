CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE= jack_module.o writeToFile.o uiUtilities.o oscillator.o sine.o saw.o square.o synth.o AMSynth.o detunedSynth.o audioManager.o main.o
TARGET=example

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:a
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
