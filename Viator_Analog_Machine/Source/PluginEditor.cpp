/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AnalogMachineAudioProcessorEditor::AnalogMachineAudioProcessorEditor (AnalogMachineAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    const int leftMargin {48};
    const int topMargin {48};
    
    sliders.push_back(&trimSlider);
    sliders.push_back(&highPassSlider);
    sliders.push_back(&lowPassSlider);
    sliders.push_back(&inGainSlider);
    sliders.push_back(&saturateSlider);
    
    sliderTracks.push_back(&trimSliderTrack);
    sliderTracks.push_back(&highPassSliderTrack);
    sliderTracks.push_back(&lowPassSliderTrack);
    sliderTracks.push_back(&inGainSliderTrack);
    sliderTracks.push_back(&saturateSliderTrack);
    
    buttons.push_back(&minusButton);
    buttons.push_back(&unityButton);
    buttons.push_back(&plusButton);
    buttons.push_back(&phaseButton);

    
    //General Slider Info
    for(auto i = 0; i < sliders.size(); i++){
        addAndMakeVisible(sliders[i]);
        sliders[i]->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        sliders[i]->setTextValueSuffix(" dB");
        sliders[i]->addListener(this);
        sliders[i]->setTextBoxStyle(Slider::TextBoxAbove, false, 96, 12);
        sliders[i]->setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0));
        sliders[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
        sliders[i]->setDoubleClickReturnValue(true, 0);
        sliders[i]->setLookAndFeel(&otherLookAndFeel);
        
        //Tracks
        addAndMakeVisible(sliderTracks[i]);
        sliderTracks[i]->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        sliderTracks[i]->addListener(this);
        sliderTracks[i]->setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, .25));
        sliderTracks[i]->setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, .5));
        sliderTracks[i]->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
        sliderTracks[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, .5));
        sliderTracks[i]->setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
        sliderTracks[i]->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 24);
        sliderTracks[i]->setDoubleClickReturnValue(true, 0);

        //Slider Varieties
        if (sliders[i] == &trimSlider){
            trimSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, TRIM_SLIDER_ID, trimSliderTrack);
            sliders[i]->setRange(-48, 48, .1);
            sliderTracks[i]->setRange(-48, 48, .1);
            sliders[i]->setBounds(leftMargin, topMargin, 152, 152);
            sliderTracks[i]->setBounds(sliders[i]->getX(), sliders[i]->getY() + 18, 152, 152);

        } else if (sliders[i] == &highPassSlider){
            highPassSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, HIGHPASS_SLIDER_ID, highPassSliderTrack);
            sliders[i]->setRange(20, 500, 2);
            sliderTracks[i]->setRange(20, 500, 2);
            sliders[i]->setTextValueSuffix(" Hz");
            sliders[i]->setBounds(sliders[0]->getX() + 172, topMargin, 152, 152);
            sliderTracks[i]->setBounds(sliders[i]->getX(), sliders[i]->getY() + 18, 152, 152);

        } else if (sliders[i] == &lowPassSlider){
            lowPassSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LOWPASS_SLIDER_ID, lowPassSliderTrack);
            sliders[i]->setRange(10000, 20000, 100);
            sliderTracks[i]->setRange(10000, 20000, 100);
            sliders[i]->setTextValueSuffix(" Hz");
            sliders[i]->setBounds(sliders[1]->getX() + 172, topMargin, 152, 152);
            sliderTracks[i]->setBounds(sliders[i]->getX(), sliders[i]->getY() + 18, 152, 152);
            
        } else if (sliders[i] == &inGainSlider){
            inGainSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, IN_GAIN_SLIDER_ID, inGainSliderTrack);
            sliders[i]->setRange(0, 9, .1);
            sliderTracks[i]->setRange(0, 9, .1);
            sliders[i]->setBounds(sliders[2]->getX() + 172, topMargin, 152, 152);
            sliderTracks[i]->setBounds(sliders[i]->getX(), sliders[i]->getY() + 18, 152, 152);
            
        } else {
            saturateSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, SATURATE_SLIDER_ID, saturateSliderTrack);
            sliders[i]->setRange(0, 24, .25);
            sliderTracks[i]->setRange(0, 24, .25);
            sliders[i]->setBounds(sliders[1]->getX() + 52, sliders[0]->getY() + 172, 200, 200);
            sliderTracks[i]->setBounds(sliders[1]->getX() + 61, sliders[i]->getY() + 27, 182, 182);
        }
        sliders[i]->setValue(sliderTracks[i]->getValue());
    }
    
    
    for(auto i = 0; i < buttons.size(); i++){
        addAndMakeVisible(buttons[i]);
        buttons[i]->addListener(this);
        buttons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .6));
        buttons[i]->setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
        buttons[i]->setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        buttons[i]->setColour(0x1000103, Colour::fromFloatRGBA(.23, .77, 1, .8));
        
        if (buttons[i] == &minusButton){
            buttons[i]->setButtonText(" -1");
            buttons[i]->setBounds(34, saturateSlider.getY() + 64, 36, 28);
        } else if (buttons[i] == &unityButton){
            buttons[i]->setButtonText("0");
            buttons[i]->setBounds(buttons[i - 1]->getX() + 48, buttons[i - 1]->getY(), 36, 28);
        } else if (buttons[i] == &plusButton){
            buttons[i]->setButtonText(" +1");
            buttons[i]->setBounds(buttons[i - 1]->getX() + 48, buttons[i - 1]->getY(), 36, 28);
        } else {
            phaseAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, PHASE_ID, phaseButton);
            buttons[i]->setButtonText("P");
            buttons[i]->setClickingTogglesState(true);
            buttons[i]->setBounds(buttons[i - 1]->getX() + 48, buttons[i - 1]->getY(), 36, 28);
        }
    }
    
    
    setSize (sliders[3]->getX() + 196, sliders[4]->getY() + 220);
    //std::cout << sliders[3]->getX() + 196 << " " << sliders[4]->getY() + 220 << std::endl;
}

AnalogMachineAudioProcessorEditor::~AnalogMachineAudioProcessorEditor()
{
}

//==============================================================================
void AnalogMachineAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour::fromFloatRGBA(0.14f, 0.16f, 0.2f, 1.0f));
    //Image background = ImageCache::getFromMemory (BinaryData::AnalogMachineBackground_png, BinaryData::AnalogMachineBackground_pngSize);
    //g.drawImageAt (background, 0, 0);
}

void AnalogMachineAudioProcessorEditor::resized()
{
    
}

void AnalogMachineAudioProcessorEditor::sliderValueChanged(Slider *slider){
    
    for(auto i = 0; i < sliderTracks.size(); i++){
    
    if (slider == sliderTracks[i]){
        sliders[i]->setValue(sliderTracks[i]->getValue());
    }
  }
}

void AnalogMachineAudioProcessorEditor::buttonClicked(Button *button){
    if (button == &minusButton){
        trimSliderTrack.setValue(trimSliderTrack.getValue() - 1);
    } else if (button == &plusButton){
        trimSliderTrack.setValue(trimSliderTrack.getValue() + 1);
    } else if (button == &unityButton){
        trimSliderTrack.setValue(0);
    }
}
