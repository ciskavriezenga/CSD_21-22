#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, double samplerate) : frequency(frequency),
  amplitude(0.5), phase(0.5), sample(0), samplerate(samplerate)
{
  std::cout << "Saw - constructor\n";
}



Saw::~Saw() {
  std::cout << "Saw - destructor\n";
}


float Saw::getSample() {
  return sample;
}

void Saw::tick() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // saw functionality comes here
  sample = 0 * amplitude;
}

//getters and setters
void Saw::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Saw::getFrequency()
{
  return frequency;
}
