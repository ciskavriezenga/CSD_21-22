#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw : public Oscillator
{
public:

  //constructors and destructor
  Saw(Clock &clock);
  Saw(Clock &clock, double frequency);
  Saw(Clock &clock, double frequency, double amplitude);
  Saw(Clock &clock, double frequency, double amplitude, double phase);
  ~Saw();
  //prevent the default constructor to be generated
  Saw() = delete;

protected:
  //functionality of this method: sample calculation
  void calculate() override;

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
