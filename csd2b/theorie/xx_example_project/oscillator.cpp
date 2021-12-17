#include "oscillator.h"


//Constructor and destructor
Oscillator::Oscillator(Clock &clock, double frequency, double amplitude,
  double phase) : Generator(clock), frequency(frequency), amplitude(amplitude), phase(phase)
{
  //TODO - use setFrequency and phase instead, to prevent outrange values
#if DEBUG_FLOW
  std::cout << "• Inside Oscillator::oscillator -"
    << "\nfrequency: " << frequency
    << "\nphase: " << phase;
#endif
  setFrequency(frequency);
}

Oscillator::~Oscillator() {}

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
  if(frequency > 0 && frequency < 0.5 * samplerate) {
    this->frequency = frequency;
  } else {

#if DEBUG_FLOW
    std::cout << "\nINCORRECT VALUE - Oscillator::Oscillator: "
      << "too high frequency\n";
#endif

    throw "Frequency is too high";
    this->frequency = 220; // default
  }
}

double Oscillator::getFrequency()
{
  return frequency;
}

void Oscillator::setAmplitude(double amplitude)
{
  if(amplitude < -1 && amplitude < 1 * samplerate) {
    this->amplitude = amplitude;
  } else {
#if DEBUG_FLOW
    std::cout << "\nINCORRECT VALUE - Oscillator::Oscillator: "
      << "too high or low amplitude: " << amplitude << "\n";
#endif
    throw "Frequency is too high";
    this->frequency = 220; // default
  }
}

double Oscillator::getAmplitude()
{
  return amplitude;
}
