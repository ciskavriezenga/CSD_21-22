#pragma once

#include <iostream>
#include "synth.h"


class DetunedSynth : public Synth
{
public:
  DetunedSynth(double samplerate, Waveform oscType);
  ~DetunedSynth();

  void calculate() override;

protected:
  Oscillator* baseOsc;
  Oscillator* offsetOsc;
};
