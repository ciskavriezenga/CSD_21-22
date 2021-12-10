#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
  //Constructor and destructor
  Square();
  Square(double frequency, double samplerate);
  ~Square();

private:
  // calculate the next sample according to square calculation
  void calcNextSample() override;
};

#endif
