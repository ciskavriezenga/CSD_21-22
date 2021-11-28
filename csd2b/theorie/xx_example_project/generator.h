#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include <iostream>

class Generator {

public:
  //Constructor and destructor
  Generator(double samplerate);
  ~Generator();

  //return the current sample
  double getSample();
  // TODO - add observer - clock that calls this function
  //abstract method, calculate the next sample, implement in derived classes
  virtual void tick() = 0;

protected:
  //abstract method, calculate the next sample, implement in derived classes
  virtual void calculate() = 0;

  double sample;
  double samplerate;

private:
  Generator();
};
#endif
