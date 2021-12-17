#include "detunedSynth.h"

DetunedSynth::DetunedSynth(double samplerate, Waveform oscType) :
  Synth(samplerate)
{
  // using baseOsc and offsetOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example
  std::cout << "• DetunedSynth constructor" << std::endl;
  synthName = "DetunedSynth";

  switch (oscType)
  {
    case SineType:
      baseOsc = new Sine(220, samplerate);
      offsetOsc = new Sine(225, samplerate);
    break;
    case SawType:
      baseOsc = new Saw(220, samplerate);
      offsetOsc = new Saw(225, samplerate);
    break;
    case SquareType:
      baseOsc = new Square(220, samplerate);
      offsetOsc = new Square(225, samplerate);
    break;
  default:
    /* code */
    break;
  }

}
DetunedSynth::~DetunedSynth()
{
  std::cout << "• DetunedSynth destructor" << std::endl;
}

void DetunedSynth::calculate()
{

}
