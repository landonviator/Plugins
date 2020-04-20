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
        g.setColour(Colour::fromFloatRGBA(.15, .15, .15, 0)); //center
        g.fillEllipse(dialArea);
        g.setColour(Colour::fromFloatRGBA(1, 1, 1, .75)); //tick color

        Path dialTick;
        dialTick.addRectangle(0, -radius + 6, 3.0f, radius * .25);
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centerX, centerY));
        g.setColour(Colour::fromFloatRGBA(0, 0, 0, 0)); //outline
        g.drawEllipse(rx, ry, diameter, diameter, 3.0f);
    }
};

class Viator_graphic_eqAudioProcessorEditor  : public AudioProcessorEditor, public Button::Listener, public Slider::Listener
{
public:
    Viator_graphic_eqAudioProcessorEditor (Viator_graphic_eqAudioProcessor&);
    ~Viator_graphic_eqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void buttonClicked(Button* button) override;
    void sliderValueChanged(Slider* slider) override;
    void setTextColors();

private:
    Viator_graphic_eqAudioProcessor& processor;
    
    OtherLookAndFeel otherLookAndFeel;
    
    //Sliders
    Slider bandOneSlider, bandTwoSlider, bandThreeSlider, bandFourSlider, bandFiveSlider, bandSixSlider, bandSevenSlider, bandEightSlider, bandNineSlider;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandOneSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandOneWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandOneNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandTwoSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandTwoWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandTwoNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandThreeSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandThreeWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandThreeNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandFourSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandFourWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandFourNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandFiveSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandFiveWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandFiveNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandSixSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandSixWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandSixNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandSevenSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandSevenWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandSevenNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandEightSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandEightWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandEightNarrowAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> bandNineSliderValue;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandNineWideAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> bandNineNarrowAttach;
    
    Slider inSlider, inSliderTrack, outSlider, outSliderTrack;
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inSliderValue;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> inSliderTrackValue;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> outSliderValue;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> outSliderTrackValue;
    
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> phaseAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> lowPassAttach;
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> highPassAttach;
    
    TextButton bandOneMinus, bandOnePlus, bandTwoMinus, bandTwoPlus, bandThreeMinus, bandThreePlus,
    bandFourMinus, bandFourPlus, bandFiveMinus, bandFivePlus, bandSixMinus, bandSixPlus, bandSevenMinus, bandSevenPlus,
    bandEightMinus, bandEightPlus, bandNineMinus, bandNinePlus, highPassToggle, lowPassToggle, phaseToggle;
    
    TextButton bandOneWide, bandOneNarrow, bandTwoWide, bandTwoNarrow, bandThreeWide, bandThreeNarrow,
    bandFourWide, bandFourNarrow, bandFiveWide, bandFiveNarrow, bandSixWide, bandSixNarrow, bandSevenWide, bandSevenNarrow,
    bandEightWide, bandEightNarrow, bandNineWide, bandNineNarrow, resetButton;
    
    std::vector<TextButton*> plusButtons;
    std::vector<TextButton*> minusButtons;
    std::vector<TextButton*> wideButtons;
    std::vector<TextButton*> narrowButtons;
    
    std::vector<TextButton*> toggleButtons;
    std::vector<Slider*> bandSliders;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Viator_graphic_eqAudioProcessorEditor)
};
