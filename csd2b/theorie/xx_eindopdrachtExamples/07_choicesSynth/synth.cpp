#include "synth.h"

Synth::Synth(double samplerate) : sample(0), samplerate(samplerate)
{
  std::cout << "\n• Synth::Synth" << std::endl;
}

Synth::~Synth()
{
  std::cout << "\n• Synth::~Synth" << std::endl;
}


void Synth::nextSample()
{
  calculate();
}


double Synth::getSample() { return sample; }

std::string Synth::waveformTypeToString(Waveform type)
{
  switch(type) {
    case Waveform::SineType:
      return "sine";
    case Waveform::SawType:
      return "saw";
    case Waveform::SquareType:
      return "square";
    default:
      return "Invalid waveform";
  }
}
