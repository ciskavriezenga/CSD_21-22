#pragma once

// CMake builds don't use an AppConfig.h, so it's safe to include juce module headers
// directly. If you need to remain compatible with Projucer-generated builds, and
// have called `juce_generate_juce_header(<thisTarget>)` in your CMakeLists.txt,
// you could `#include <JuceHeader.h>` here instead, to make all your module headers visible.
#include <juce_gui_extra/juce_gui_extra.h>
#include "CustomSlider.h"



class LabelSliderComponent : public juce::Component
{
public:
  //==============================================================================
  LabelSliderComponent();

  //==============================================================================
  void paint (juce::Graphics&) override;
  void resized() override;

private:
  //==============================================================================
  juce::Point<int> size = juce::Point<int>(500, 500);
  juce::Point<float> margin = juce::Point<float>(0.02f, 0.02f);
  juce::Point<float> labelSize = juce::Point<float>(1.0f, 0.04f);
  juce::Point<float> sliderSize = juce::Point<float>(0.5f, 0.5f);

  CustomSlider slider;
  juce::Label label;
};
