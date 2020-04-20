/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/

//class OtherLookAndFeel : public LookAndFeel_V4{
//public:
//    void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override{
//
//        float diameter = jmin(width, height) * 0.65;
//        float radius = diameter * 0.5;
//        float centerX = x + width * 0.5;
//        float centerY = y + height * 0.5;
//        float rx = centerX - radius;
//        float ry = centerY - radius;
//        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
//
//        Rectangle<float> dialArea (rx, ry, diameter, diameter);
//        g.setColour(Colour::fromFloatRGBA(0.20f, 0.22f, 0.24f, .75)); //center
//        g.fillEllipse(dialArea);
//        g.setColour(Colour::fromFloatRGBA(.2, .77, 1, .75)); //tick color
//
//
//        Path dialTick;
//        dialTick.addRectangle(0, -radius + 3, 3.0f, radius * .5);
//        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centerX, centerY));
//        g.setColour(Colour::fromFloatRGBA(0, 0, 0, .25)); //outline
//        g.drawEllipse(rx, ry, diameter, diameter, 1.0f);
//    }
//
//
//};

class LpvtrimmerAudioProcessorEditor  : public AudioProcessorEditor, Button::Listener, Slider::Listener
{
public:
    LpvtrimmerAudioProcessorEditor (LpvtrimmerAudioProcessor&);
    ~LpvtrimmerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void setTextColors(double color1, double color2, double color3, double alpha);
    void buttonBackgrounds(double color1, double color2, double color3, double alpha);
    void sliderValueChanged(Slider *slider) override;
    void checkFineState();

private:
    std::unique_ptr<Slider> inGainSlider;
    std::unique_ptr<Label> phaseLabel, fineLabel, inGainLabel;
    std::unique_ptr<GroupComponent> gainGroup;
    
    TextButton gainPlusButton, gainMinusButton, unityButton, gainPlusLess, gainMinusLess;
    
    ToggleButton phaseButton;
    ToggleButton buttonChanger;
    
    Image background;

    LpvtrimmerAudioProcessor& processor;
    
public:
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inGainSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> phaseAttach;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LpvtrimmerAudioProcessorEditor)
};
