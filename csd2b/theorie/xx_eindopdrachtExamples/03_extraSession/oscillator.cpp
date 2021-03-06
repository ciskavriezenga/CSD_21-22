#include "oscillator.h"

Oscillator::Oscillator(double frequency, double samplerate) :
  frequency(frequency), amplitude(1.0), phase(0), sample(0),
  samplerate(samplerate)
  {
    // TODO - use setFrequency & question Mila
  }

Oscillator::~Oscillator() {}

void Oscillator::initialize(double samplerate)
{
  this->samplerate = samplerate;
}

double Oscillator::getSample() {
  return sample;
}

void Oscillator::tick() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;

  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;

  // let subclasses calculate the next sample
  calcNextSample();
}

//getters and setters
void Oscillator::setFrequency(double frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

double Oscillator::getFrequency()
{
  return frequency;
}
