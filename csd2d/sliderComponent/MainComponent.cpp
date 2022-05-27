#include "MainComponent.h"




//==============================================================================
MainComponent::MainComponent()
{
    // make label slider visible
    addAndMakeVisible(labelSliderComponent, 1);
    setSize (size.x, size.y);
}


void MainComponent::paint (juce::Graphics& g)
{
    juce::Colour bgColour = juce::Colour(0, 0, 255);
    g.fillAll (bgColour);

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::red);
    g.drawText ("Topleft MainComponent", getLocalBounds(), juce::Justification::topLeft, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    labelSliderComponent.setBoundsRelative (margin.x, margin.y,
      1.0f - margin.x * 2.0f, 1.0f - margin.y * 2.0f);
}
