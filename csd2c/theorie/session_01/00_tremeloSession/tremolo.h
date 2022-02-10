#pragma once

#include <iostream>
#include "oscillator.h"

class Tremolo
{
public:
  Tremolo(float freq, int samplerate);
  ~Tremolo();

  float processFrame(float sample);
  // setters and getters
  void setModFreq(float freq);
private:
  Oscillator* osc;
  float modSignal;
};
