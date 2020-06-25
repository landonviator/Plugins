/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class OtherLookAndFeel : public LookAndFeel_V4{
public:
    void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override{
        
        float diameter = jmin(width, height) * 0.65;
        float radius = diameter * 0.5;
        float centerX = x + width * 0.5;
        float centerY = y + height * 0.5;
        float rx = centerX - radius;
        float ry = centerY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        g.setColour(Colour::fromFloatRGBA(0.20f, 0.22f, 0.24f, .45)); //center
        g.fillEllipse(dialArea);
        g.setColour(Colour::fromFloatRGBA(.2, .77, 1, .75)); //tick color
        
        
        Path dialTick;
        dialTick.addRectangle(0, -radius + 3, 3.0f, radius * .5);
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centerX, centerY));
        g.setColour(Colour::fromFloatRGBA(0, 0, 0, .25)); //outline
        g.drawEllipse(rx, ry, diameter, diameter, 1.0f);
    }
};

class Viator_element_eqAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Viator_element_eqAudioProcessorEditor (Viator_element_eqAudioProcessor&);
    ~Viator_element_eqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    Slider subSlider, bassSlider, earthSlider, fogSlider, stingSlider, airSlider;
    
    std::vector<Slider*> sliders;
    std::vector<std::string> sliderLabels;
    
    OtherLookAndFeel otherLookAndFeel;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Viator_element_eqAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Viator_element_eqAudioProcessorEditor)
};
