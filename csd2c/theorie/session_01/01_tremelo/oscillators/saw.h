#ifndef _SAW_H_
#define _SAW_H_
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  //Constructor and destructor
  Saw();
  Saw(double frequency, double samplerate);
  ~Saw();

private:
  // calculate the next sample according to saw calculation
  void calcNextSample() override;
};

#endif
