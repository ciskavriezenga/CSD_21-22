#include "sine.h"

//Constructors and destructor
Sine::Sine(Clock &clock, double samplerate) : Sine(clock, samplerate, 0, 0) {}

Sine::Sine(Clock &clock, double samplerate, double frequency) :
  Sine(clock, samplerate, frequency, 0.5, 0) {}

Sine::Sine(Clock &clock, double samplerate, double frequency, double amplitude) :
  Sine(clock, samplerate, frequency, amplitude, 0) {}

Sine::Sine(Clock &clock, double samplerate, double frequency, double amplitude,
  double phase) : Oscillator (clock, samplerate, frequency, amplitude, phase) {
    #if DEBUG_FLOW
      std::cout << "• Inside Sine::Sine(double samplerate, double frequency, "
      << "double amplitude, double phase)\n";
    #endif
  }

Sine::~Sine() {}

//override calculate method
//this method contains the sample calculation
void Sine::calculate()
{
  //translate phase to -PI..PI
  static double tempPhase = 0;
  tempPhase = (phase - 0.5) * M_PI * 2.0;
  // generate approximation of sinewave, using polynomial
  if (tempPhase < 0)
    sample =  1.27323954 * tempPhase + .405284735 * tempPhase * tempPhase;
  else
    sample = 1.27323954 * tempPhase - 0.405284735 * tempPhase * tempPhase;
  sample *= amplitude;
}
