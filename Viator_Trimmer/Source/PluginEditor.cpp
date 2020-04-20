/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LpvtrimmerAudioProcessorEditor::LpvtrimmerAudioProcessorEditor (LpvtrimmerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (340, 160);
    
    inGainSlider.reset(new Slider ("newSlider"));
    addAndMakeVisible(inGainSlider.get());
    inGainSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, INGAIN_ID, *inGainSlider);
    inGainSlider->setRange(-60.0, 24.0, 0.25);
    inGainSlider->setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    inGainSlider->setTextValueSuffix(" db");
    inGainSlider->setTextBoxStyle(Slider::TextBoxLeft, false, 86, 24);
    inGainSlider->setColour(Slider::backgroundColourId, Colour::fromFloatRGBA(0, 0, 0, .3));
    inGainSlider->setColour(Slider::trackColourId, Colour::fromFloatRGBA(.23, .77, 1, .5));
    inGainSlider->setColour(Slider::thumbColourId, Colour::fromFloatRGBA(1, 1, 1, 1));
    inGainSlider->setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, .5)); //text box border
    inGainSlider->setBounds(26, 22, 292, 48);
    
    inGainLabel.reset(new Label ("newSlider"));
    addAndMakeVisible(inGainLabel.get());
    inGainLabel->setBounds(316, 0, 100, 96);
    
    gainGroup.reset(new GroupComponent("newGainGroup"));
    //addAndMakeVisible(gainGroup.get());
    gainGroup->setText("Gain");
    gainGroup->setColour(0x1005400, Colour::fromFloatRGBA(1, 1, 1, .5));
    gainGroup->setBounds(8, 8, 324, 144);
    
    addAndMakeVisible(gainMinusButton);
    gainMinusButton.addListener(this);
    gainMinusButton.setButtonText("-1.5 db");
    gainMinusButton.setToggleState(false, dontSendNotification);
    gainMinusButton.setBounds(24, 74, 88, 30);
    
    addAndMakeVisible(gainPlusButton);
    gainPlusButton.addListener(this);
    gainPlusButton.setButtonText("+1.5 db");
    gainPlusButton.setToggleState(false, dontSendNotification);
    gainPlusButton.setBounds(124, 74, 88, 30);
    
    addAndMakeVisible(gainPlusLess);
    gainPlusLess.addListener(this);
    gainPlusLess.setButtonText("+0.25 db");
    gainPlusLess.setToggleState(false, dontSendNotification);
    gainPlusLess.setBounds(124, 74, 88, 30);
    
    addAndMakeVisible(gainMinusLess);
    gainMinusLess.addListener(this);
    gainMinusLess.setButtonText("-0.25 db");
    gainMinusLess.setToggleState(false, dontSendNotification);
    gainMinusLess.setBounds(24, 74, 88, 30);
    
    addAndMakeVisible(unityButton);
    unityButton.addListener(this);
    unityButton.setButtonText("Unity");
    unityButton.setToggleState(false, dontSendNotification);
    unityButton.setBounds(224, 74, 88, 30);
    
    addAndMakeVisible(phaseButton);
    phaseAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, PHASE_ID, phaseButton);
    phaseButton.setColour(0x1006502, Colour::fromRGB(92, 208, 255));
    phaseButton.setBounds(22, 116, 21, 21);
    
    phaseLabel.reset(new Label ("phaseLabel"));
    addAndMakeVisible(phaseLabel.get());
    phaseLabel->setText("Phase", dontSendNotification);
    phaseLabel->setBounds(44, 116, 48, 24);
    
    addAndMakeVisible(buttonChanger);
    buttonChanger.addListener(this);
    buttonChanger.setBounds(122, 116, 88, 21);
    buttonChanger.setColour(0x1006502, Colour::fromRGB(92, 208, 255));
    buttonChanger.setToggleState(processor.buttonState, dontSendNotification);
    
    fineLabel.reset(new Label ("fineLabel"));
    addAndMakeVisible(fineLabel.get());
    fineLabel->setText("Fine", dontSendNotification);
    fineLabel->setBounds(144, 114, 48, 24);
    
    setTextColors(1, 1, 1, .45);
    buttonBackgrounds(0.9f, 0.92f, 0.95f, 0);
    checkFineState();
}

LpvtrimmerAudioProcessorEditor::~LpvtrimmerAudioProcessorEditor()
{
}

//==============================================================================
void LpvtrimmerAudioProcessorEditor::paint (Graphics& g)
{
    //g.fillAll(Colour::fromFloatRGBA(0.14f, 0.16f, 0.2f, 1.0f));
    Image background = ImageCache::getFromMemory (BinaryData::pluginBackground_png, BinaryData::pluginBackground_pngSize);
    g.drawImageAt (background, 0, 0);
}

void LpvtrimmerAudioProcessorEditor::resized()
{
    
}

void LpvtrimmerAudioProcessorEditor::buttonClicked(Button *button)
{
    if (button == &gainMinusButton)
    {
        inGainSlider->setValue(inGainSlider->getValue() - 1.5);
    }
    
    if (button == &gainPlusButton)
    {
        inGainSlider->setValue(inGainSlider->getValue() + 1.5);
    }
    
    if (button == &unityButton)
    {
        inGainSlider->setValue(0);
    }
    
    if (button == &gainMinusLess){
        inGainSlider->setValue(inGainSlider->getValue() - 0.25);
    }
    
    if (button == &gainPlusLess){
        inGainSlider->setValue(inGainSlider->getValue() + 0.5);
    }
    
    if (button == &buttonChanger){
        if (buttonChanger.getToggleState() == false){
            gainMinusLess.setVisible(false);
            gainPlusLess.setVisible(false);
            gainMinusButton.setVisible(true);
            gainPlusButton.setVisible(true);
            processor.buttonState = false;
        }
            else {
                gainMinusLess.setVisible(true);
                gainPlusLess.setVisible(true);
                gainMinusButton.setVisible(false);
                gainPlusButton.setVisible(false);
                processor.buttonState = true;
        }
    }
}

void LpvtrimmerAudioProcessorEditor::sliderValueChanged(Slider *slider){
    
}

void LpvtrimmerAudioProcessorEditor::setTextColors(double color1, double color2, double color3, double alpha){
    unityButton.setColour(0x1000102, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    unityButton.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    unityButton.setColour(0x1000101, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainMinusLess.setColour(0x1000102, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainPlusLess.setColour(0x1000102, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainPlusButton.setColour(0x1000102, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainPlusButton.setColour(0x1000102, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainMinusButton.setColour(0x1000102, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    inGainLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    inGainSlider->setColour(0x1001400, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    phaseLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    fineLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainGroup->setColour(0x1005410, Colour::fromFloatRGBA(color1, color2, color3, alpha));
}

void LpvtrimmerAudioProcessorEditor::buttonBackgrounds(double color1, double color2, double color3, double alpha){
    gainMinusButton.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainPlusButton.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainPlusLess.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainMinusLess.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    unityButton.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
     buttonChanger.setColour(0x1000100, Colour::fromFloatRGBA(color1, color2, color3, alpha));
}

void LpvtrimmerAudioProcessorEditor::checkFineState(){
    if (processor.buttonState == false){
        gainMinusLess.setVisible(false);
        gainPlusLess.setVisible(false);
        gainMinusButton.setVisible(true);
        gainPlusButton.setVisible(true);
    }
    else {
        gainMinusLess.setVisible(true);
        gainPlusLess.setVisible(true);
        gainMinusButton.setVisible(false);
        gainPlusButton.setVisible(false);
    }
}



