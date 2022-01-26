#pragma once
#include <iostream>

class Oscillator
{
public:
  Oscillator(double frequency, double samplerate);
  virtual ~Oscillator();

  void initialize(double samplerate);

  // go to next sample
  void tick();

  // setters and getters
  // return the current sample
  double getSample();

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();
protected:
  virtual void calcNextSample() = 0;

  double frequency;
  double amplitude;
  double phase;
  // sample contains the current sample
  double sample;
  double samplerate;

};
