#include "sine.h"
#include "math.h"


Sine::Sine() : Sine(0, 0)
{}

Sine::Sine(float frequency, float samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calcNextSample()
{
  sample = sin(M_PI * 2 * phase);
  // TODO - move to base class
  sample *= amplitude;
}
