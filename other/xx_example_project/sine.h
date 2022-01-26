#ifndef _SINE_H_
#define _SINE_H_
#include "oscillator.h"

class Sine : public Oscillator
{
public:

  //constructors and destructor
  Sine(Clock &clock);
  Sine(Clock &clock, double frequency);
  Sine(Clock &clock, double frequency, double amplitude);
  Sine(Clock &clock, double frequency, double amplitude, double phase);
  ~Sine();
  //prevent the default constructor to be generated
  Sine() = delete;

  //functionallity of this method: sample calculation
  void calculate() override;

/*
  NOTE: we could use a seperate calculate method
  in that case -> overriding getSample is not necessary.
*/

};

#endif
