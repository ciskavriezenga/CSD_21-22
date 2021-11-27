#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw : public Oscillator
{
public:

  //constructors and destructor
  Saw(double samplerate);
  Saw(double samplerate, double frequency);
  Saw(double samplerate, double frequency, double amplitude);
  Saw(double samplerate, double frequency, double amplitude, double phase);
  ~Saw();
  //prevent the default constructor to be generated
  Saw() = delete;

protected:
  //override calculate
  //this method contains the sample calculation
  void calculate();

/*
  NOTE: we could use a seperate calculate method
  in that case -> overriding getSample is not necessary.
*/
private:
  //values used to calculate the saw wave
  //phase increment
  const double phaseIncrement;
  //
  double smoothY;
  //wrapped phase
  double wPhase;

};

#endif
