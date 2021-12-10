#include "synth.h"

Synth::Synth(float midiPitchm, double samplerate) : sample(0)
{
  sine.initialize(samplerate);
  setMidiPitch(midiPitch);
}

Synth::~Synth() {}

void Synth::tick()
{
  sine.tick();
  sample = sine.getSample();
}

double Synth::getSample()
{
  return sample;
}

void Synth::setMidiPitch(float pitch)
{
  // TODO check if pitch is different
  // TODO - check if pitch is in range
  midiPitch = pitch;
  double freq = mtof(midiPitch);
  sine.setFrequency(freq);
}

double Synth::mtof(float pitch)
{
  // TODO - implement mtof functionality
  return 440;
}
