#ifndef _SINE_H_
#define _SINE_H_
#include "oscillator.h"

class Sine : public Oscillator
{
public:

  //constructors and destructor
  Sine(double samplerate);
  Sine(double samplerate, double frequency);
  Sine(double samplerate, double frequency, double amplitude);
  Sine(double samplerate, double frequency, double amplitude, double phase);
  ~Sine();
  //prevent the default constructor to be generated
  Sine() = delete;

  //override calculate
  //this method contains the sample calculation
  void calculate();

/*
  NOTE: we could use a seperate calculate method
  in that case -> overriding getSample is not necessary.
*/


};

#endif
