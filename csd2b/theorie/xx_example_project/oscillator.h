#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
#include "math.h"
#include "generator.h"

class Oscillator : public Generator
{
public:
  //Constructor and destructor
  Oscillator(double samplerate, double frequency, double amplitude,
    double phase);
  virtual ~Oscillator();

  void tick() override;
  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();
  void setAmplitude(double amplitude);
  double getAmplitude();

  //NOTE - do we need a setter for phase? for now -> not using one

protected:
  double frequency;
  double amplitude;
  double phase;

};

#endif
