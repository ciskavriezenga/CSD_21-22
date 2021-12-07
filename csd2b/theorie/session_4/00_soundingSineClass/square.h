#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>

class Square
{
public:
  //Constructor and destructor
  Square(float frequency, double samplerate);
  ~Square();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};

#endif
