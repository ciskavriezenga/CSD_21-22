#include "saw.h"
#include "math.h"

Saw::Saw() : Saw(0, 0)
{}

Saw::Saw(double frequency, double samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "Saw - constructor\n";
}


Saw::~Saw()
{
  std::cout << "Saw - destructor\n";
}

void Saw::calcNextSample()
{
  // calculate saw wave
  sample = phase * 2.0 - 1.0;
  sample *= amplitude;
}
