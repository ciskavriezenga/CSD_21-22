#include "AMSynth.h"

AMSynth::AMSynth(double samplerate, Waveform oscType) : Synth(samplerate),
  modDepth(0.25), modFreq(50), carFreq(220), carAmp(0.3)
{
  // using modulatorOsc and carrierOsc instead of creating
  // oscillators dynamically in the constructor
  // for the sake of the example

  synthName = "AMSynth";
  std::cout << "• AMSynth constructor" << std::endl;

  switch (oscType)
  {
    case SineType:
      modulatorOsc = new Sine(modFreq, samplerate);
      carrierOsc = new Sine(carFreq, samplerate);
    break;
    case SawType:
      modulatorOsc = new Saw(modFreq, samplerate);
      carrierOsc = new Saw(carFreq, samplerate);
    break;
    case SquareType:
      modulatorOsc = new Square(modFreq, samplerate);
      carrierOsc = new Square(carFreq, samplerate);
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
  modulatorOsc->nextSample();
  carrierOsc->nextSample();
  sample = carrierOsc->getSample() * (carAmp + (modulatorOsc->getSample() * modDepth));
}

void AMSynth::setModDepth(double modDepth)
{
  this->modDepth = modDepth;
}

void AMSynth::setModFreq(double modFreq)
{
  this->modFreq = modFreq;
}

void AMSynth::setFreq(double carFreq)
{
  this->carFreq = carFreq;
}

void AMSynth::setAmp(double carAmp)
{
  this->carAmp = carAmp;
}
