#pragma once

class CustomLookAndFeel : public juce::LookAndFeel_V4 {
  public:
  CustomLookAndFeel()
  {
      setColour(juce::Slider::thumbColourId, juce::Colours::white);
      setColour(juce::Slider::backgroundColourId, juce::Colour(150, 150, 150));
      setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(50, 50, 250));
      setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(20, 20, 250));

      /* ColourIds: backgroundColourId , thumbColourId, trackColourId,
                    rotarySliderFillColourId, rotarySliderOutlineColourId,
                    textBoxTextColourId, textBoxBackgroundColourId,
                    textBoxHighlightColourId, textBoxOutlineColourId */

  }

  void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                         const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&) override
  {
      // calculate radius of rotary knob
      float paddingPercentage = 0.1f;
      float minSize = juce::jmin(width / 2, height / 2);
      float padding = minSize * paddingPercentage;
      auto radius = (float) minSize - padding;
      // calculate position and size rotary knob
      auto centreX = (float) x + (float) width  * 0.5f;
      auto centreY = (float) y + (float) height * 0.5f;
      auto rx = centreX - radius;
      auto ry = centreY - radius;
      auto rw = radius * 2.0f;
      auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

      // fill background
      g.fillAll(findColour (juce::Slider::backgroundColourId));

      // draw rotary knob
      g.setColour(findColour(juce::Slider::rotarySliderFillColourId));
      g.fillEllipse(rx, ry, rw, rw);
      g.setColour(findColour(juce::Slider::rotarySliderOutlineColourId));
      g.drawEllipse(rx, ry, rw, rw, 1.0f);

      // draw rotary thumb
      juce::Path p;
      auto thumbLength = radius * 0.66f;
      auto thumbThickness = thumbLength * 0.33f;
      float thumbCornerSize = thumbThickness * 0.5f;
      p.addRoundedRectangle(-thumbThickness * 0.5f, -radius, thumbThickness, thumbLength, thumbCornerSize);
      p.applyTransform(juce::AffineTransform::rotation(angle).translated(centreX, centreY));
      g.setColour(findColour(juce::Slider::thumbColourId));
      g.fillPath(p);
  }
};
