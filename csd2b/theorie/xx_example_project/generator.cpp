#include "generator.h"

Generator::Generator(Clock& clock) : sample(0),
  samplerate(clock.getSamplerate()), clock(&clock)
{
#if DEBUG_FLOW
  std::cout << "• Inside Generator::Generator"
    << "- samplerate: " << samplerate << "\n";
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
