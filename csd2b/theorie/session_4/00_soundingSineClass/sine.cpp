#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, double samplerate) : frequency(frequency),
  amplitude(0.5), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;

  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  sample = sin(M_PI * 2 * phase) * amplitude;
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
