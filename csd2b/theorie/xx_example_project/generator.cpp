#include "generator.h"

Generator::Generator(Clock& clock, double samplerate) : clock(&clock),
  sample(0), samplerate(samplerate)
{
#if DEBUG_FLOW
  std::cout << "• Inside Generator::Generator (double samplerate)"
    << ", samplerate: " << samplerate << "\n";
#endif
}

Generator::~Generator() {}

double Generator::getSample() {
  // if the clock is at the next index --> calculate new sample
  if((clock->getClockIndex()) >= nextSampleIndex) {
    nextSampleIndex = clock->getClockIndex() + 1;
    calcNextSample();
  }
  return sample;
}
