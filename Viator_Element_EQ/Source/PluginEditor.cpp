/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Viator_element_eqAudioProcessorEditor::Viator_element_eqAudioProcessorEditor (Viator_element_eqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    int topMargin = 64;
    int leftMargin = 24;
    
    //Make and optimize a vector for the sliders
    sliders.reserve(6);
    sliders = {
        &subSlider, &bassSlider, &earthSlider, &fogSlider, &stingSlider, &airSlider
    };
    
    
    
    //All slider attributes except attachments
    for (size_t i = 0; i < sliders.size(); i++) {
        addAndMakeVisible(sliders[i]);
        sliders[i]->setRange(-12, 12, .1);
        sliders[i]->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        sliders[i]->setTextBoxStyle(Slider::TextBoxAbove, false, 72, 32);
        sliders[i]->setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
        sliders[i]->setColour(0x1001400, Colour::fromFloatRGBA(1.0, 1.0, 1.0, 0.5)); //text box text
        sliders[i]->setLookAndFeel(&otherLookAndFeel);
        sliders[i]->setDoubleClickReturnValue(true, 0);
        sliders[i]->setTextValueSuffix(" dB");
        
        if (sliders[i] == &subSlider){
            sliders[i]->setBounds(leftMargin, topMargin, 148, 148);
        } else {
            sliders[i]->setBounds(sliders[i - 1]->getX() + 128, topMargin, 148, 148);
        }
    }
    
    //Set up all slider attachments
    for (size_t i = 0; i < sliders.size(); i++) {
        if (sliders[i] == &subSlider){
            subAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, subSliderId, subSlider);
        } else if (sliders[i] == &bassSlider){
            bassAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, bassSliderId, bassSlider);
        } else if (sliders[i] == &earthSlider){
            earthAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, earthSliderId, earthSlider);
        } else if (sliders[i] == &fogSlider){
            fogAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, fogSliderId, fogSlider);
        } else if (sliders[i] == &stingSlider){
            stingAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, stingSliderId, stingSlider);
        } else {
            airAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, airSliderId, airSlider);
        }
    }
    
    setSize (832, 300);
}

Viator_element_eqAudioProcessorEditor::~Viator_element_eqAudioProcessorEditor()
{
}

//==============================================================================
void Viator_element_eqAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(Colour::fromFloatRGBA(0.14f, 0.16f, 0.2f, 1.0f));
}

void Viator_element_eqAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
