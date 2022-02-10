#ifndef _FAST_SINE_H_
#define _FAST_SINE_H_
#include <iostream>
#include "oscillator.h"

class FastSine : public Oscillator
{
public:
  //Constructor and destructor
  FastSine();
  FastSine(float frequency, float samplerate);
  ~FastSine();

private:
  // calculate the next sample according to fast sine calculation
  void calcNextSample() override;
};

#endif
