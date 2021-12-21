#pragma once

#include <iostream>
#include "sine.h"
#include "saw.h"
#include "square.h"

class Synth
{
public:
  Synth(double samplerate);
  virtual ~Synth();
  // NOTE: needs to be same order as the waveFormOptions string array
  enum Waveform {
    SineType = 0, // ensure enum starts at 0
    SawType,
    SquareType,
    Size // 3
  };
  // setters and getters

  void nextSample();
  virtual void calculate() = 0;
  double getSample();

  // static method because this method does not depend on objects
  static std::string waveformTypeToString(Waveform type);

protected:
  // contains current sample value
  double sample;
  double samplerate;
  // for the sake of logging
  std::string synthName;

};
