#include "oscillator.h"


Oscillator::Oscillator(float freq, float amp)
{
  std::cout << "Inside Oscillator constructor\n";
  this->freq = freq;
  this->amp = amp;
}

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}


// setters and getters
void Oscillator::setFreq(float freq)
{
  if(freq > 0 && freq < 22050) {
    this->freq = freq;
  } else {
    std::cout << "The frequency value is incorrect"
    << " please present a value in the interval [0, 22049]\n";
  }
}

float Oscillator::getFreq()
{
  return freq;
}
