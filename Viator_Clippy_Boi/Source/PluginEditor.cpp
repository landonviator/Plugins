/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Viator_clippy_boiAudioProcessorEditor::Viator_clippy_boiAudioProcessorEditor (Viator_clippy_boiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    int leftMargin = 8;
    int topMargin = 8;
    
    
    
    sliders.reserve(3);
    sliders = {
      &inGainSlider, &saturationSlider, &trimSlider
    };
    
    tracks.reserve(3);
    tracks = {
      &inGainTrack, &saturationTrack, &trimTrack
    };
    
    //Saturation Stuff
    addAndMakeVisible(saturationGroup);
    saturationGroup.setText("Saturation");
    saturationGroup.setColour(0x1005400, Colour::fromFloatRGBA(1, 1, 1, .5));
    saturationGroup.setColour(0x1005410, Colour::fromFloatRGBA(1, 1, 1, .5));
    saturationGroup.setBounds(leftMargin, topMargin, 448, 276);
    
    for (size_t i {0}; i < sliders.size(); i++) {
        addAndMakeVisible(sliders[i]);
        sliders[i]->addListener(this);
        sliders[i]->setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        sliders[i]->setRange(0, 24, 0.25f);
        sliders[i]->setTextValueSuffix(" dB");
        sliders[i]->setTextBoxStyle(Slider::TextBoxBelow, false, 128, 24);
        sliders[i]->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
        sliders[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0.5));
        sliders[i]->setLookAndFeel(&otherLookAndFeel);
        
        if(sliders[i] == &inGainSlider){
            sliders[i]->setBounds(saturationGroup.getX() + 16, saturationGroup.getY() + (saturationGroup.getHeight() * .12) + 32, 144, 144);
        } else {
            sliders[i]->setBounds(sliders[i -1]->getX() + sliders[i -1]->getWidth() - 16, saturationGroup.getY() + (saturationGroup.getHeight() * .12) + 32, 144, 144);
        }
    }
    
    for (size_t i {0}; i < tracks.size(); i++) {
        addAndMakeVisible(tracks[i]);
        tracks[i]->addListener(this);
        tracks[i]->setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        tracks[i]->setTextValueSuffix(" dB");
        tracks[i]->setTextBoxStyle(Slider::TextBoxBelow, false, 128, 24);
        tracks[i]->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
        tracks[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
        tracks[i]->setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
        tracks[i]->setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, .25));
        tracks[i]->setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, .5));
        
        if (tracks[i] == &inGainTrack){
            
            inGainTrack.setRange(-24, 24, 0.5);
            inGainSlider.setRange(-24, 24, 0.5);
            inputAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, inputSliderId, inGainTrack);
            tracks[i]->setBounds(saturationGroup.getX() + 19, saturationGroup.getY() + (saturationGroup.getHeight() * .12) + 35, 138, 138);
            
        } else if (tracks[i] == &saturationTrack){
            
            saturationTrack.setRange(0, 24, 0.5);
            saturationSlider.setRange(0, 24, 0.5);
            saturationAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, saturationSliderId, saturationTrack);
            tracks[i]->setBounds(saturationSlider.getX() + 3, saturationGroup.getY() + (saturationGroup.getHeight() * .12) + 35, 138, 138);
            
        } else {
            
            trimTrack.setRange(-24, 24, 0.5);
            trimSlider.setRange(-24, 24, 0.5);
            outputAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, outputSliderId, trimTrack);
            tracks[i]->setBounds(trimSlider.getX() + 3, saturationGroup.getY() + (saturationGroup.getHeight() * .12) + 35, 138, 138);
        }
    }
    
        addAndMakeVisible(forcedButton);
        forcedButton.addListener(this);
        forcedButton.setClickingTogglesState(true);
        forcedButton.setButtonText("Force");
        forcedButton.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
        forcedButton.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, .1));
        forcedButton.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, 0.5));
        forcedButton.setColour(0x1000103, Colour::fromFloatRGBA(.23, .77, 1, 1.0));
        forcedButton.setBounds(saturationSlider.getX() + 35, saturationGroup.getY() + 32, 72, 30);
        
        addAndMakeVisible(saturationModel);
        saturationModel.addItem("Soft", 1);
        saturationModel.addItem("Hard", 2);
        saturationModel.setText("Model");
        saturationModel.addListener(this);
        saturationModel.setColour(0x1000b00, Colour::fromFloatRGBA(0, 0, 0, 0));
        saturationModel.setColour(0x1000a00, Colour::fromFloatRGBA(1, 1, 1, 0.5f));
        saturationModel.setColour(0x1000c00, Colour::fromFloatRGBA(1, 1, 1, 0.5f));
        saturationModel.setColour(0x1000d00, Colour::fromFloatRGBA(1, 1, 1, 0.5f));
        saturationModel.setColour(0x1000f00, Colour::fromFloatRGBA(1, 1, 1, 0.5f));
        saturationModel.setColour(0x1000e00, Colour::fromFloatRGBA(1, 1, 1, 0));

        saturationModel.setBounds(inGainSlider.getX() + 20, saturationGroup.getY() + 32, 98, 32);
    
        addAndMakeVisible(autoButton);
        autoButton.setButtonText("Auto");
        autoButton.setColour(0x1006502, Colour::fromFloatRGBA(.23, .77, 1, 1.0));
        autoButton.setColour(0x1006503, Colour::fromFloatRGBA(1, 1, 1, 0.5));
        autoButton.setColour(0x1006501, Colour::fromFloatRGBA(1, 1, 1, 0.5));
        autoButton.setBounds(trimSlider.getX() + 56, saturationGroup.getY() + 32, 24, 24);
        autoButton.changeWidthToFitText();
    
    setSize (saturationGroup.getWidth() + 16, saturationGroup.getHeight() + 16);
}

Viator_clippy_boiAudioProcessorEditor::~Viator_clippy_boiAudioProcessorEditor()
{
}

//==============================================================================
void Viator_clippy_boiAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour::fromFloatRGBA(0.14f, 0.16f, 0.2f, 1.0f));
}

void Viator_clippy_boiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void Viator_clippy_boiAudioProcessorEditor::sliderValueChanged(Slider *slider){
    for (size_t i {0}; i < sliders.size(); i++) {
        if (slider == tracks[i]){
            sliders[i]->setValue(tracks[i]->getValue());
        }
    }
}

void Viator_clippy_boiAudioProcessorEditor::buttonClicked(Button *button){
    
}

void Viator_clippy_boiAudioProcessorEditor::comboBoxChanged(ComboBox *comboBoxThatHasChanged){
    
}
