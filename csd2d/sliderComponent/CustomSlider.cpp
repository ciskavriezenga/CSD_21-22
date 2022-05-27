#include "CustomSlider.h"


CustomSlider::CustomSlider() : CustomSlider(0.0f, 1.0f) {}

CustomSlider::CustomSlider(float rangeMin, float rangeMax)
{
  // slider GUI config
  setLookAndFeel (&customLookAndFeel);
  setSliderStyle(juce::Slider::Rotary);
  int tbHeight = (int)((float) height * (1.0f - percHeightRotary));
  setTextBoxStyle(TextEntryBoxPosition::TextBoxBelow, false, width, tbHeight);
  showTextBox();

  // slider functionality
  setRange(rangeMin, rangeMax);
}
