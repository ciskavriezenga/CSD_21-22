#pragma once
#include <iostream>

class Oscillator
{
public:
  Oscillator(float frequency, float samplerate);
  virtual ~Oscillator();

  void initialize(float samplerate);

  // go to next sample
  void tick();

  // setters and getters
  // return the current sample
  float getSample();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();
protected:
  virtual void calcNextSample() = 0;

  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  float samplerate;

};
