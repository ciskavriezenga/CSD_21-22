#include "tremolo.h"
#include "saw.h"
#include "sine.h"
#include "square.h"

Tremolo::Tremolo(float samplerate, float modDepth, float modFreq,
      WaveformType waveformType) : m_modDepth(modDepth)
{
  // instantiate the oscillator, depending on the passed waveform type
  switch (waveformType) {
  case WaveformType::SINE:
  {
    m_osc = new Sine(modFreq, samplerate);
    break;
  }
  case WaveformType::SAW:
  {
    m_osc = new Saw(modFreq, samplerate);
    break;
  }
  case WaveformType::SQUARE:
  {
    // TODO: alter calculation of to create a non-aliasing square,
    // similar to the calculation within the Saw class
    m_osc = new Square(modFreq, samplerate);
    break;
  }
  default:
    throw "Tremelo::Tremelo - incorrect waveformType.";
    break;
  }
}

Tremolo::~Tremolo()
{
  // release dynamically allocated oscillator object.
  delete m_osc;
  m_osc = nullptr;
}

float Tremolo::processFrame(float input)
{
  // transform sine in range [-1, 1] to range [0, 1]
  m_modSignal  = m_osc->genNextSample() * 0.5 + 0.5;
  // apply modDepth
  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;
  // apply modulation signal to input
  m_sample = input * m_modSignal;
  return m_sample;
}

void Tremolo::setModFreq(float modFreq)
{
  if(modFreq >= m_modFreqMin && modFreq <= m_modFreqMax) {
    m_osc->setFrequency(modFreq);
  } else {
    std::cout << "• Tremelo::setModFreq - modFreq is incorrect"
      << " please pass value between " << m_modFreqMin << " and " << m_modFreqMax
      << std::endl;
  }

}
