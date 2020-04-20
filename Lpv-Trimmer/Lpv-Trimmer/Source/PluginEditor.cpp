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
    setSize (562, 348);
    
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
    addAndMakeVisible(gainGroup.get());
    gainGroup->setText("Gain");
    gainGroup->setColour(0x1005400, Colour::fromFloatRGBA(1, 1, 1, .5));
    gainGroup->setBounds(8, 8, 324, 144);
    
    highCutSlider.reset(new Slider("newHighCut"));
    addAndMakeVisible(highCutSlider.get());
    highCutSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, HIGHCUT_ID, *highCutSlider);
    highCutSlider->addListener(this);
    highCutSlider->setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    highCutSlider->setRange(20, 20000, 1);
    highCutSlider->setSkewFactorFromMidPoint(10000);
    highCutSlider->setTextValueSuffix(" Hz");
    highCutSlider->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 24);
    highCutSlider->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    highCutSlider->setBounds(191, 188, 144, 144);
    highCutSlider->setLookAndFeel(&otherLookAndFeel);
    
    highCutTrack.reset(new Slider("newHighCutTrack"));
    addAndMakeVisible(highCutTrack.get());
    highCutTrackSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, HIGHCUT_ID, *highCutTrack);
    highCutTrack->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    highCutTrack->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 24);
    highCutTrack->addListener(this);
    highCutTrack->setRange(20, 20000, 1);
    highCutTrack->setSkewFactorFromMidPoint(10000);
    highCutTrack->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    highCutTrack->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    highCutTrack->setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
    highCutTrack->setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, .25));
    highCutTrack->setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, .5));
    highCutTrack->setBounds(194, 191, 138, 138);
    
    lowCutSlider.reset(new Slider("newLowCut"));
    addAndMakeVisible(lowCutSlider.get());
    lowCutSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LOWCUT_ID, *lowCutSlider);
    lowCutSlider->addListener(this);
    lowCutSlider->setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    lowCutSlider->setRange(20, 20000, 1);
    lowCutSlider->setSkewFactorFromMidPoint(250);
    lowCutSlider->setTextValueSuffix(" Hz");
    lowCutSlider->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 24);
    lowCutSlider->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    lowCutSlider->setBounds(16, 188, 144, 144);
    lowCutSlider->setLookAndFeel(&otherLookAndFeel);
    
    lowCutTrack.reset(new Slider("newLowCutTrack"));
    addAndMakeVisible(lowCutTrack.get());
    lowCutTrackSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LOWCUT_ID, *lowCutTrack);
    lowCutTrack->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    lowCutTrack->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 24);
    lowCutTrack->addListener(this);
    lowCutTrack->setRange(20, 20000, 1);
    lowCutTrack->setSkewFactorFromMidPoint(250);
    lowCutTrack->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    lowCutTrack->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    lowCutTrack->setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
    lowCutTrack->setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, .25));
    lowCutTrack->setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, .5));
    lowCutTrack->setBounds(19, 191, 138, 138);
    
    lowCutLabel.reset(new Label("newLowCutLaebl"));
    addAndMakeVisible(lowCutLabel.get());
    lowCutLabel->setText("Low Cut", dontSendNotification);
    lowCutLabel->setBounds(55, 162, 92, 48);
    
    highCutLabel.reset(new Label("newHighCutLaebl"));
    addAndMakeVisible(highCutLabel.get());
    highCutLabel->setText("High Cut", dontSendNotification);
    highCutLabel->setBounds(228, 162, 92, 48);
    
    filterGroup.reset(new GroupComponent("newFilterGroup"));
    addAndMakeVisible(filterGroup.get());
    filterGroup->setText("Filter");
    filterGroup->setColour(0x1005400, Colour::fromFloatRGBA(1, 1, 1, .5));
    filterGroup->setBounds(8, 160, 324, 184);
    
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
    
    consoleGroup.reset(new GroupComponent("newConsoleGroup"));
    addAndMakeVisible(consoleGroup.get());
    consoleGroup->setText("Output");
    consoleGroup->setColour(0x1005400, Colour::fromFloatRGBA(1, 1, 1, .5));
    consoleGroup->setBounds(336, 8, 218, 336);
    
    saturateSlider.reset(new Slider("newSaturate"));
    addAndMakeVisible(saturateSlider.get());
    saturateSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, SATURATE_ID, *saturateSlider);
    saturateSlider->addListener(this);
    saturateSlider->setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    saturateSlider->setRange(0, 24, 0.25f);
    saturateSlider->setTextValueSuffix(" dB \n Saturation");
    saturateSlider->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    saturateSlider->setTextBoxStyle(Slider::TextBoxBelow, false, 128, 36);
    saturateSlider->setBounds(349, 18, 144, 144);
    saturateSlider->setLookAndFeel(&otherLookAndFeel);
    
    saturateTrack.reset(new Slider("newSaturateTrack"));
    addAndMakeVisible(saturateTrack.get());
    saturateTrackSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, SATURATE_ID, *saturateTrack);
    saturateTrack->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    saturateTrack->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 36);
    saturateTrack->addListener(this);
    saturateTrack->setRange(0, 24, 0.25f);
    saturateTrack->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    saturateTrack->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    saturateTrack->setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
    saturateTrack->setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, .25));
    saturateTrack->setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, .5));
    saturateTrack->setBounds(352, 21, 138, 138);
    
    outSlider.reset(new Slider("newOut"));
    addAndMakeVisible(outSlider.get());
    outSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, OUT_ID, *outSlider);
    outSlider->addListener(this);
    outSlider->setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    outSlider->setRange(-60, 24, 0.25f);
    outSlider->setTextValueSuffix(" dB \n Volume");
    outSlider->setTextBoxStyle(Slider::TextBoxBelow, false, 128, 36);
    outSlider->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    outSlider->setBounds(349, 188, 144, 144);
    outSlider->setLookAndFeel(&otherLookAndFeel);
    
    outSliderTrack.reset(new Slider("newOutTrack"));
    addAndMakeVisible(outSliderTrack.get());
    outTrackSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, OUT_ID, *outSliderTrack);
    outSliderTrack->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    outSliderTrack->setTextBoxStyle(Slider::TextBoxBelow, false, 72, 36);
    outSliderTrack->addListener(this);
    outSliderTrack->setRange(-60, 24, 0.25f);
    outSliderTrack->setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    outSliderTrack->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    outSliderTrack->setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
    outSliderTrack->setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, .25));
    outSliderTrack->setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, .5));
    outSliderTrack->setBounds(352, 191, 138, 138);
    
    forceButton.reset(new ToggleButton("newForce"));
    addAndMakeVisible(forceButton.get());
    forceAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, FORCE_ID, *forceButton);
    forceButton->setColour(0x1006502, Colour::fromRGB(92, 208, 255));
    forceButton->setBounds(476, 66, 21, 21);
    
    forceLabel.reset(new Label("newForce"));
    addAndMakeVisible(forceLabel.get());
    forceLabel->setText("Force", dontSendNotification);
    forceLabel->setBounds(498, 64, 48, 24);
    
    autoButton.reset(new ToggleButton("newAuto"));
    addAndMakeVisible(autoButton.get());
    autoAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, AUTO_ID, *autoButton);
    autoButton->addListener(this);
    autoButton->setColour(0x1006502, Colour::fromRGB(92, 208, 255));
    autoButton->setBounds(476, 238, 21, 21);
    
    autoLabel.reset(new Label("newAuto"));
    addAndMakeVisible(autoLabel.get());
    autoLabel->setText("Auto", dontSendNotification);
    autoLabel->setBounds(498, 236, 48, 24);
    
    setTextColors(1, 1, 1, .75);
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
    if (slider == highCutTrack.get()){
        highCutSlider->setValue(highCutTrack->getValue());
    }
    
    if (slider == lowCutTrack.get()){
        lowCutSlider->setValue(lowCutTrack->getValue());
    }
    
    //if auto is on, the output equals the negative dB of the drive
    if (slider == saturateTrack.get()){
        saturateSlider->setValue(saturateTrack->getValue());
        if (*processor.treeState.getRawParameterValue(AUTO_ID) == 1){
            outSliderTrack->setValue(saturateTrack->getValue() * -1.0f);
        }
        if (*processor.treeState.getRawParameterValue(FORCE_ID) == true){
            outSliderTrack->setValue(saturateTrack->getValue() * -.5f);
        }
    }
    if (slider == outSliderTrack.get()){
        outSlider->setValue(outSliderTrack->getValue());
    }
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
    lowCutLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    highCutLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    inGainSlider->setColour(0x1001400, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    lowCutSlider->setColour(0x1001400, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    highCutSlider->setColour(0x1001400, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    saturateSlider->setColour(0x1001400, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    outSlider->setColour(0x1001400, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    phaseLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    fineLabel->setColour(0x1000281, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    gainGroup->setColour(0x1005410, Colour::fromFloatRGBA(color1, color2, color3, alpha));
    consoleGroup->setColour(0x1005410, Colour::fromFloatRGBA(color1, color2, color3, alpha));
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



