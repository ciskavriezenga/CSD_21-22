#include "square.h"
#include "math.h"

Square::Square(float frequency, double samplerate) : frequency(frequency),
  amplitude(0.5), phase(0.5), sample(0), samplerate(samplerate)
{
  std::cout << "Square - constructor\n";
}



Square::~Square() {
  std::cout << "Square - destructor\n";
}


float Square::getSample() {
  return sample;
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // square functionality comes here
  sample = 0 * amplitude;
}

//getters and setters
void Square::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Square::getFrequency()
{
  return frequency;
}
