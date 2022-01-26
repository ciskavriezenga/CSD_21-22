#include <iostream>
#include <thread>
#include "writeToFile.h"
#include "circBuffer.h"
#include "sine.h"

#define SAMPLERATE 44100

int main(int argc,char **argv)
{
  // with a 44100 samplerate and 882 frequency --> 50 samples for one cycle
  float freq = 882;
  // set delay to approximately a quarter cycle
  CircBuffer circBuffer(200, 12);

  circBuffer.logAllSettings();

  Sine sine(freq, SAMPLERATE);
  WriteToFile fileWriter("output.csv", true);

  // generate 200 samples
  // write sum of output of both the sine directly and the circBuffer to a file
  float sineSample = 0;
  for(int i = 0; i < 200; i++) {
    sineSample = sine.getSample();
    circBuffer.write(sineSample);
    std::cout << circBuffer.read();
    fileWriter.write(std::to_string(sineSample + circBuffer.read()) + "\n");
    // go to next sample
    sine.tick();
    circBuffer.tick();
  }

  std::cout << "\n***** DONE ***** "
    << "\nWrote the sum of the a sine oscillator and a "
    << "delayed value to output.csv." << std::endl;

  //end the program
  return 0;

} // main()
