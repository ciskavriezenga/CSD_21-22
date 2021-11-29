#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include <iostream>
#include "macros.h"
#include "clock.h"

// inherits from observer to implement the observer pattern
class Generator {

public:
  //Constructor and destructor
  Generator(Clock& clock);
  //prevent the default constructor to be generated
  Generator() = delete;
  virtual ~Generator();

  //return the current sample
  double getSample();

protected:
  //abstract method, calculate the next sample, implement in derived classes
  virtual void calcNextSample() = 0;

  // sample holds the last generated sample
  double sample;
  double samplerate;

private:
  // the index of the next sample to calculate
  uint nextSampleIndex = 0;
  // The clock this signal runs at
  Clock* clock = nullptr;
};
#endif
