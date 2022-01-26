#include "tremolo.h"
#include "saw.h"
#include "sine.h"
#include "square.h"

Tremolo::Tremolo(float samplerate, float modDepth, float modFreq,
      WaveformType waveformType) : modDepth(modDepth)
{
  // instantiate the oscillator, depending on the passed waveform type
  switch (waveformType) {
  case WaveformType::SINE:
  {
    osc = new Sine(modFreq, samplerate);
    break;
  }
  case WaveformType::SAW:
  {
    osc = new Saw(modFreq, samplerate);
    break;
  }
  case WaveformType::SQUARE:
  {
    // TODO: alter calculation of to create a non-aliasing square,
    // similar to the calculation within the Saw class
    osc = new Square(modFreq, samplerate);
    break;
  }
  default:
    break;
  }
}

Tremolo::~Tremolo()
{
  // release dynamically allocated oscillator object.
  delete osc;
  osc = nullptr;
}

void Tremolo::process(float* inbuf, float* outbuf, int numFrames)
{
  float modSignal = 0;

  // apply Tremolo effect to inbuf values and store result in outbuf
  for(int i = 0; i < numFrames; i++) {
    // transform sine in range [-1, 1] to range [0, 1]
    modSignal = osc->getSample() * 0.5 + 0.5;
    // apply modDepth
    modSignal *= modDepth;
    modSignal += 1.0 - modDepth;
    // apply modulation signal to input
    outbuf[i] = inbuf[i] * modSignal;
    // update sine sample
    osc->tick();
  }
}

void Tremolo::setModFreq(float modFreq)
{
  if(modFreq >= modFreqMin && modFreq <= modFreqMax) {
    osc->setFrequency(modFreq);
  } else {
    std::cout << "• Tremelo::setModFreq - modFreq is incorrect"
      << " please pass value between " << modFreqMin << " and " << modFreqMax
      << std::endl;
  }

}
