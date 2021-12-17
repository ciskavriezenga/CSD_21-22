#include "AMSynth.h"

AMSynth::AMSynth(double samplerate, Waveform oscType) : Synth(samplerate)
{
  // using modulatorOsc and carrierOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example

  synthName = "AMSynth";
  std::cout << "• AMSynth constructor" << std::endl;

  switch (oscType)
  {
    case SineType:
      modulatorOsc = new Sine(220, samplerate);
      carrierOsc = new Sine(225, samplerate);
    break;
    case SawType:
      modulatorOsc = new Saw(220, samplerate);
      carrierOsc = new Saw(225, samplerate);
    break;
    case SquareType:
      modulatorOsc = new Square(220, samplerate);
      carrierOsc = new Square(225, samplerate);
    break;
  default:
    /* code */
    break;
  }
}

AMSynth::~AMSynth()
{
  std::cout << "• AMSynth destructor" << std::endl;
}

void AMSynth::calculate()
{

}
