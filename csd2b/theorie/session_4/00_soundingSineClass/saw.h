#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>

class Saw
{
public:
  //Constructor and destructor
  Saw(float frequency, double samplerate);
  ~Saw();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};

#endif
