#include "effect.h"
#include <iostream>

Effect::Effect(float dryWet) {
  setDryWet(dryWet);
}

Effect::~Effect() {}

// process frame
float Effect::processFrame(float input)
{
  // TODO - add bypass functionality
  m_sample = input * wetDry + applyEffect(input) * dryWet;
  return m_sample;
}

// returns the last outputted sample
float Effect::getSample()
{
  return m_sample;
}

void Effect::setDryWet(float dryWet)
{
  if(dryWet < 0 || dryWet > 1) {
    throw "Effect::setDryWet - dryWet value is not in range [0, 1]";
  }
  this->dryWet = dryWet;
  // cache 1.0 - dryWet used to calculate mix of dry wet signal
  wetDry = 1.0f - dryWet;
}
