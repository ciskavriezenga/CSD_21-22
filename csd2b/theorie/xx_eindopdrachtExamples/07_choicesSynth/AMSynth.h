#pragma once

#include <iostream>
#include "synth.h"

class AMSynth : public Synth
{
public:
  AMSynth(double samplerate, Waveform oscType);
  ~AMSynth();

  enum OscType {
    Modulator,
    Carrier
  };
  void calculate() override;
  // setters and getters
#if 0
  // TODO this is the next step, to also allow user to set waveform per
  // oscillator
  void setWaveform(Waveform type, OscType oscType);
  static std::string oscTypeToString(OscType type);
#else
  void setWaveform(Waveform type);
#endif

protected:
  Oscillator* modulatorOsc;
  Oscillator* carrierOsc;
};
