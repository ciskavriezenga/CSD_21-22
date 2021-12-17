#pragma once
#include <iostream>
#include "jack_module.h"
// TODO - use interface SelectionUtil instead!
#include "uiUtilities.h"
#include "synth.h"

class AudioManager
{
public:
  AudioManager();
  ~AudioManager();

  enum SynthType {
    AMSynthType = 0,
    DetunedSynthType,
    Size // 2
  };

  // setters and getters
  bool changeSynth();

  void assignAudioCallback();
  void end();
  // static method because this method does not depend on objects
  static std::string synthTypeToString(SynthType type);

protected:
  Synth* synth;
  JackModule* jack;

  bool changeSynth(SynthType synthType);
  void deleteSynth();
};
