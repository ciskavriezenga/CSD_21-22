#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "oscillator.h"

class Square : public Oscillator
{
public:

  //constructors and destructor
  Square(double samplerate);
  Square(double samplerate, double frequency);
  Square(double samplerate, double frequency, double phase);
  ~Square();
  //prevent the default constructor to be generated
  Square() = delete;

  //override calculate
  //this method contains the sample calculation
  void calculate();

/*
  NOTE: we could use a seperate calculate method
  in that case -> overriding getSample is not necessary.
*/


};

#endif
