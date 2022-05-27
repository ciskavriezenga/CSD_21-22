#include "LabelSliderComponent.h"




//==============================================================================
LabelSliderComponent::LabelSliderComponent() {
  // make slider and label visible
  addAndMakeVisible(slider);
  addAndMakeVisible(label);
  label.setText("Funky Knob", juce::NotificationType::dontSendNotification);
  label.setJustificationType(juce::Justification::centred);
  label.setColour(juce::Label::backgroundColourId, juce::Colour(50, 50, 50));
}

void LabelSliderComponent::paint (juce::Graphics& g)
{
  // set bg colour to light gray
  g.fillAll(juce::Colour(200, 200, 200));

  // set font settings & add text to left top
  g.setFont(juce::Font (16.0f));
  g.setColour(juce::Colours::green);
  g.drawText("TopLeft LabelSliderComponent", getLocalBounds(), juce::Justification::topLeft, true);
}

void LabelSliderComponent::resized() {
  // set width to full width minus margin
  label.setBoundsRelative(margin.x, margin.y, 1.0f - margin.x * 2.0f, labelSize.y);
  slider.setBoundsRelative(margin.x, margin.y + labelSize.y,
    1.0f - margin.x * 2.0f, 1.0f - margin.y * 2.0f - labelSize.y);
}
