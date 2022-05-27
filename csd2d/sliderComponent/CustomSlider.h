#pragma once

// CMake builds don't use an AppConfig.h, so it's safe to include juce module headers
// directly. If you need to remain compatible with Projucer-generated builds, and
// have called `juce_generate_juce_header(<thisTarget>)` in your CMakeLists.txt,
// you could `#include <JuceHeader.h>` here instead, to make all your module headers visible.
#include <juce_gui_extra/juce_gui_extra.h>
#include "CustomLookAndFeel.h"



class CustomSlider : public juce::Slider
{
public:
  CustomSlider();
  CustomSlider(float rangeMin, float rangeMax);

  //==============================================================================
  //void paint (juce::Graphics&) override;
//  void resized() override;
  // NOTE! for sake of test and simplicity - public width and ...
  int width = 200;
  int height = 200;

private:
  float percHeightRotary = 0.8f;
  CustomLookAndFeel customLookAndFeel;
};
