#include "generator.h"

// private, forcing unreachable default constructor
Generator::Generator() : sample(0) {}

Generator::Generator(double samplerate) : sample(0), samplerate(samplerate){
#if DEBUG_FLOW
  std::cout << "• Inside Generator::Generator (double samplerate)"
    << ", samplerate: " << samplerate << "\n";
#endif
}

Generator::~Generator() {}

double Generator::getSample() { return sample; }
