#include "fastsine.h"

//Constructors and destructor
FastSine::FastSine(double samplerate) : FastSine(samplerate, 0, 0) {}

FastSine::FastSine(double samplerate, double frequency) :
  FastSine(samplerate, frequency, 0) {}

FastSine::FastSine(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

FastSine::~FastSine() {}

//override calculate method
//this method contains the sample calculation
void FastSine::calculate()
{
  //std::cout << "\n";
  //translate phase to -PI..PI
  static double tempPhase = 0;
  tempPhase = (phase - 0.5) * PI_2;
  //std::cout << phase;
  if (tempPhase < 0)
    sample =  1.27323954 * tempPhase + .405284735 * tempPhase * tempPhase;
  else
    sample = 1.27323954 * tempPhase - 0.405284735 * tempPhase * tempPhase;
}
