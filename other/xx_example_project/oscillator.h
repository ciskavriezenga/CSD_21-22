#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
#include "math.h"
#include "generator.h"

class Oscillator : public Generator
{
public:
  //Constructor and destructor
  Oscillator(Clock &clock, double frequency, double amplitude,
    double phase);
  virtual ~Oscillator();

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();
  void setAmplitude(double amplitude);
  double getAmplitude();

protected:
  // updates the phase value and then calls calculate
  void calcNextSample() override;
  virtual void calculate() = 0;
  double frequency;
  double amplitude;
  double phase;
};

#endif
