#include <iostream>
#include "uiUtilities.h"
#include "synth.h"

int main()
{

  // create a string array with the waveform type options
  std::string* waveformOptions = new std::string[Synth::Waveform::Size];
  for(int i = 0; i < Synth::Waveform::Size; i++) {
     waveformOptions[i] = Synth::waveformTypeToString((Synth::Waveform)i);
  }

  Synth::Waveform waveType = (Synth::Waveform)
    UIUtilities::retrieveSelectionIndex(waveformOptions, Synth::Waveform::Size);

  Synth synth;
  synth.setWaveform(waveType);
}
