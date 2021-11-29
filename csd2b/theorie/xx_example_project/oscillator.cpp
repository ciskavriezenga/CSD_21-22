#include "oscillator.h"


//Constructor and destructor
Oscillator::Oscillator(Clock &clock, double samplerate, double frequency, double amplitude,
  double phase) : Generator(clock, samplerate), frequency(frequency), amplitude(amplitude), phase(phase)
{
  //TODO - use setFrequency and phase instead, to prevent outrange values
#if DEBUG_FLOW
  std::cout << "• Inside Oscillator::oscillator (double samplerate,"
    << "double frequency, double amplitude, double phase)"
    << "\nfrequency: " << frequency
    << "\nphase: " << phase;
#endif
}

Oscillator::~Oscillator()
{

}

void Oscillator::calcNextSample()
{
  phase += frequency / samplerate;
  //wrap phase from 0 to 1
  if(phase >= 1) phase = phase - 1;
  //calculate new sample
  calculate();
}

void Oscillator::setFrequency(double frequency)
{
  if(frequency > 0 && frequency < 0.5 * samplerate)
  this->frequency = frequency;
}

double Oscillator::getFrequency()
{
  return frequency;
}
