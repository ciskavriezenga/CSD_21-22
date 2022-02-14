#pragma once

class Effect
{
public:
  // drywet: drywet balance
  // drywet == 0:     dry
  // 0 < drywet < 1:  mix
  // drywet == 1:     wet
  // default is wet
  Effect(float dryWet = 1.0);
  virtual ~Effect();

  // process frame
  void processFrame(float& input, float& output);
  // returns the last outputted sample
  float getSample();

  void setDryWet(float dryWet);

protected:
  // pure virtual method
  virtual void applyEffect(float& input, float& output) = 0;

private:
  // balance between dry and wet signal
  float dryWet;
  float wetDry; // = 1 - dryWet
  // cache last sample
  float m_sample;
  /*
   * NOTE: other possible extra base class functionality:
   * • bypass
   */

};
