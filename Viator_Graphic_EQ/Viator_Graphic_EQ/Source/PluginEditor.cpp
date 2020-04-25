/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Viator_graphic_eqAudioProcessorEditor::Viator_graphic_eqAudioProcessorEditor (Viator_graphic_eqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    setSize (1140, 420);
    
    const int leftMargin {24};
    const int topMargin {22};
    
    plusButtons.reserve(9);
    plusButtons = {&bandOnePlus, &bandTwoPlus, &bandThreePlus, &bandFourPlus, &bandFivePlus, &bandSixPlus, &bandSevenPlus, &bandEightPlus, &bandNinePlus};
    
    minusButtons.reserve(9);
    minusButtons = {&bandOneMinus, &bandTwoMinus, &bandThreeMinus, &bandFourMinus, &bandFiveMinus, &bandSixMinus, &bandSevenMinus, &bandEightMinus, &bandNineMinus};
    
    wideButtons.reserve(9);
    wideButtons = {&bandOneWide, &bandTwoWide, &bandThreeWide, &bandFourWide, &bandFiveWide, &bandSixWide, &bandSevenWide, &bandEightWide, &bandNineWide};
    
    narrowButtons.reserve(9);
    narrowButtons = {&bandOneNarrow, &bandTwoNarrow, &bandThreeNarrow, &bandFourNarrow, &bandFiveNarrow, &bandSixNarrow, &bandSevenNarrow, &bandEightNarrow, &bandNineNarrow};
    
    toggleButtons.reserve(3);
    toggleButtons = {&lowPassToggle, &highPassToggle, &phaseToggle};
    
    bandSliders.reserve(9);
    bandSliders = {&bandOneSlider, &bandTwoSlider, &bandThreeSlider, &bandFourSlider, &bandFiveSlider, &bandSixSlider, &bandSevenSlider, &bandEightSlider, &bandNineSlider};

    
    //Sliders
    for (size_t i = 0; i < bandSliders.size(); i++){
        //General slider info
        addAndMakeVisible(bandSliders[i]);
        bandSliders[i]->setRange(-18, 18, .5);
        bandSliders[i]->setSliderStyle(Slider::SliderStyle::LinearVertical);
        bandSliders[i]->setTextBoxStyle(Slider::TextBoxAbove, false, 72, 32);
        bandSliders[i]->setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.0));
        bandSliders[i]->setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
        
        //Slider specifics
        if (bandSliders[i] == &bandOneSlider){
            bandOneSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_ONE_ID, bandOneSlider);
            bandSliders[i]->setBounds(leftMargin + 146, topMargin, 68, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n60 Hz");
        } else if (bandSliders[i] == &bandTwoSlider){
            bandTwoSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_TWO_ID, bandTwoSlider);
            bandSliders[i]->setBounds(bandOneSlider.getX() + bandOneSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n125 Hz");
        } else if (bandSliders[i] == &bandThreeSlider){
            bandThreeSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_THREE_ID, bandThreeSlider);
            bandSliders[i]->setBounds(bandTwoSlider.getX() + bandTwoSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n250 Hz");
        } else if (bandSliders[i] == &bandFourSlider){
            bandFourSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_FOUR_ID, bandFourSlider);
            bandSliders[i]->setBounds(bandThreeSlider.getX() + bandThreeSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n500 Hz");
        } else if (bandSliders[i] == &bandFiveSlider){
            bandFiveSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_FIVE_ID, bandFiveSlider);
            bandSliders[i]->setBounds(bandFourSlider.getX() + bandFourSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n1 kHz");
        } else if(bandSliders[i] == &bandSixSlider){
            bandSixSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_SIX_ID, bandSixSlider);
            bandSliders[i]->setBounds(bandFiveSlider.getX() + bandFiveSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n2 kHz");
        } else if (bandSliders[i] == &bandSevenSlider){
            bandSevenSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_SEVEN_ID, bandSevenSlider);
            bandSliders[i]->setBounds(bandSixSlider.getX() + bandSixSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n4 kHz");
        } else if (bandSliders[i] == &bandEightSlider){
            bandEightSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_EIGHT_ID, bandEightSlider);
            bandSliders[i]->setBounds(bandSevenSlider.getX() + bandSevenSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n8 kHz");
        } else {
            bandNineSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_NINE_ID, bandNineSlider);
            bandSliders[i]->setBounds(bandEightSlider.getX() + bandEightSlider.getWidth() + 24, topMargin, 64, 256);
            bandSliders[i]->setTextValueSuffix(" dB\n1 kHz");
        }
        
    }
    
    //Gain Minus Buttons
    for(size_t i = 0; i < minusButtons.size(); i++){
        addAndMakeVisible(minusButtons[i]);
        minusButtons[i]->addListener(this);
        minusButtons[i]->setButtonText("-");
        minusButtons[i]->setToggleState(false, dontSendNotification);
        minusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
        minusButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
        
        if (minusButtons[i] == &bandOneMinus){
            minusButtons[i]->setBounds(leftMargin + 152, 280, 28, 30);
        } else if (minusButtons[i] == &bandTwoMinus){
            minusButtons[i]->setBounds(bandOneSlider.getX() + bandOneSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else if (minusButtons[i] == &bandThreeMinus){
            minusButtons[i]->setBounds(bandTwoSlider.getX() + bandTwoSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else if (minusButtons[i] == &bandFourMinus){
            minusButtons[i]->setBounds(bandThreeSlider.getX() + bandThreeSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else if (minusButtons[i] == &bandFiveMinus){
            minusButtons[i]->setBounds(bandFourSlider.getX() + bandFourSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else if (minusButtons[i] == &bandSixMinus){
            minusButtons[i]->setBounds(bandFiveSlider.getX() + bandFiveSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else if (minusButtons[i] == &bandSevenMinus){
            minusButtons[i]->setBounds(bandSixSlider.getX() + bandSixSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else if (minusButtons[i] == &bandEightMinus){
            minusButtons[i]->setBounds(bandSevenSlider.getX() + bandEightSlider.getWidth() + 4 + 24, 280, 28, 30);
        } else {
            minusButtons[i]->setBounds(bandEightSlider.getX() + bandEightSlider.getWidth() + 4 + 24, 280, 28, 30);
        }
    }
    
    //Gain Plus Buttons
    for (size_t i = 0; i < plusButtons.size(); i++) {
        addAndMakeVisible(plusButtons[i]);
        plusButtons[i]->addListener(this);
        plusButtons[i]->setButtonText("+");
        plusButtons[i]->setToggleState(false, dontSendNotification);
        plusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
        plusButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
        
        if (plusButtons[i] == &bandOnePlus){
           plusButtons[i]->setBounds(bandOneMinus.getX() + bandOneMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandTwoPlus){
           plusButtons[i]->setBounds(bandTwoMinus.getX() + bandTwoMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandThreePlus){
            plusButtons[i]->setBounds(bandThreeMinus.getX() + bandThreeMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandFourPlus){
            plusButtons[i]->setBounds(bandFourMinus.getX() + bandFourMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandFivePlus){
            plusButtons[i]->setBounds(bandFiveMinus.getX() + bandFiveMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandSixPlus){
            plusButtons[i]->setBounds(bandSixMinus.getX() + bandSixMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandSevenPlus){
            plusButtons[i]->setBounds(bandSevenMinus.getX() + bandSevenMinus.getWidth(), 280, 28, 30);
        } else if (plusButtons[i] == &bandEightPlus){
            plusButtons[i]->setBounds(bandEightMinus.getX() + bandEightMinus.getWidth(), 280, 28, 30);
        } else {
            plusButtons[i]->setBounds(bandNineMinus.getX() + bandNineMinus.getWidth(), 280, 28, 30);
        }
        
    }
    
    //Wide Buttons
    for (size_t i = 0; i < wideButtons.size(); i++) {
        addAndMakeVisible(wideButtons[i]);
        wideButtons[i]->addListener(this);
        wideButtons[i]->setButtonText("Wide");
        wideButtons[i]->setClickingTogglesState(true);
        wideButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        wideButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
        wideButtons[i]->setBounds(minusButtons[i]->getX(), minusButtons[i]->getY() + 42, 56, 30);
        
        if (wideButtons[i] == &bandOneWide){
            bandOneWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDONEWIDE_ID, bandOneWide);
            wideButtons[i]->setBounds(leftMargin + 152, bandOneMinus.getY() + bandOneMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandTwoWide){
            bandTwoWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTWOWIDE_ID, bandTwoWide);
            wideButtons[i]->setBounds(bandTwoMinus.getX(), bandTwoMinus.getY() + bandTwoMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandThreeWide){
            bandThreeWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTHREEWIDE_ID, bandThreeWide);
            wideButtons[i]->setBounds(bandThreeMinus.getX(), bandThreeMinus.getY() + bandThreeMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandFourWide){
            bandFourWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFOURWIDE_ID, bandFourWide);
            wideButtons[i]->setBounds(bandFourMinus.getX(), bandFourMinus.getY() + bandFourMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandFiveWide){
            bandFiveWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFIVEWIDE_ID, bandFiveWide);
            wideButtons[i]->setBounds(bandFiveMinus.getX(), bandFiveMinus.getY() + bandFiveMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandSixWide){
            bandSixWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSIXWIDE_ID, bandSixWide);
            wideButtons[i]->setBounds(bandSixMinus.getX(), bandSixMinus.getY() + bandSixMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandSevenWide){
            bandSevenWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSEVENWIDE_ID, bandSevenWide);
            wideButtons[i]->setBounds(bandSevenMinus.getX(), bandSevenMinus.getY() + bandSevenMinus.getHeight() + 12, 56, 30);
        } else if (wideButtons[i] == &bandEightWide){
            bandEightWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDEIGHTWIDE_ID, bandEightWide);
            wideButtons[i]->setBounds(bandEightMinus.getX(), bandEightMinus.getY() + bandEightMinus.getHeight() + 12, 56, 30);
        } else {
            bandNineWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDNINEWIDE_ID, bandNineWide);
            wideButtons[i]->setBounds(bandNineMinus.getX(), bandNineMinus.getY() + bandNineMinus.getHeight() + 12, 56, 30);
        }
    
        if (processor.treeState.getParameter(BANDONEWIDE_ID)){
            bandOneWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandOneWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDTWOWIDE_ID)){
            bandTwoWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandTwoWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDTHREEWIDE_ID)){
            bandThreeWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandThreeWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDFOURWIDE_ID)){
            bandFourWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandFourWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDFIVEWIDE_ID)){
            bandFiveWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandFiveWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDSIXWIDE_ID)){
            bandSixWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandSixWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDSEVENWIDE_ID)){
            bandSevenWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandSevenWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDEIGHTWIDE_ID)){
            bandEightWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandEightWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDNINEWIDE_ID)){
            bandNineWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandNineWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
    }
    
    //Narrow Buttons
    for (size_t i = 0; i < narrowButtons.size(); i++) {
        addAndMakeVisible(narrowButtons[i]);
        narrowButtons[i]->addListener(this);
        narrowButtons[i]->setButtonText("Slim");
        narrowButtons[i]->setClickingTogglesState(true);
        narrowButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        narrowButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
        
        if (narrowButtons[i] == &bandOneNarrow){
            bandOneNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDONENARROW_ID, bandOneNarrow);
            narrowButtons[i]->setBounds(leftMargin + 152, bandOneWide.getY() + bandOneWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandTwoNarrow){
            bandTwoNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTWONARROW_ID, bandTwoNarrow);
            narrowButtons[i]->setBounds(bandTwoMinus.getX(), bandTwoWide.getY() + bandTwoWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandThreeNarrow){
            bandThreeNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTHREENARROW_ID, bandThreeNarrow);
            narrowButtons[i]->setBounds(bandThreeMinus.getX(), bandThreeWide.getY() + bandThreeWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandFourNarrow){
            bandFourNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFOURNARROW_ID, bandFourNarrow);
            narrowButtons[i]->setBounds(bandFourMinus.getX(), bandFourWide.getY() + bandFourWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandFiveNarrow){
            bandFiveNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFIVENARROW_ID, bandFiveNarrow);
            narrowButtons[i]->setBounds(bandFiveMinus.getX(), bandFiveWide.getY() + bandFiveWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandSixNarrow){
            bandSixNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSIXNARROW_ID, bandSixNarrow);
            narrowButtons[i]->setBounds(bandSixMinus.getX(), bandSixWide.getY() + bandSixWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandSevenNarrow){
            bandSevenNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSEVENNARROW_ID, bandSevenNarrow);
            narrowButtons[i]->setBounds(bandSevenMinus.getX(), bandSevenWide.getY() + bandSevenWide.getHeight() + 12, 56, 30);
        } else if (narrowButtons[i] == &bandEightNarrow){
            bandEightNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDEIGHTNARROW_ID, bandEightNarrow);
            narrowButtons[i]->setBounds(bandEightMinus.getX(), bandEightWide.getY() + bandEightWide.getHeight() + 12, 56, 30);
        } else {
            bandNineNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDNINENARROW_ID, bandNineNarrow);
            narrowButtons[i]->setBounds(bandNineMinus.getX(), bandNineWide.getY() + bandNineWide.getHeight() + 12, 56, 30);
        }
        
        if (processor.treeState.getParameter(BANDONENARROW_ID)){
            bandOneNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandOneNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDTWONARROW_ID)){
            bandTwoNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandTwoNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDTHREENARROW_ID)){
            bandThreeNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandThreeNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDFOURNARROW_ID)){
            bandFourNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandFourNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDFIVENARROW_ID)){
            bandFiveNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandFiveNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDSIXNARROW_ID)){
            bandSixNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandSixNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDSEVENNARROW_ID)){
            bandSevenNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandSevenNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDEIGHTNARROW_ID)){
            bandEightNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandEightNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
        if (processor.treeState.getParameter(BANDNINENARROW_ID)){
            bandNineNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
            bandNineNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
        }
        
    }

    
    
    //In Slider
    addAndMakeVisible(inSlider);
    inSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, IN_ID, inSlider);
    inSlider.setRange(0, 12, .1);
    inSlider.setTextValueSuffix(" db In");
    inSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    inSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 96, 32);
    inSlider.setColour(Slider::backgroundColourId, Colour::fromFloatRGBA(0, 0, 0, .75));
    inSlider.setColour(Slider::trackColourId, Colour::fromFloatRGBA(0, 0, 0, .75));
    inSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(1, 1, 1, 1));
    inSlider.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    inSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    inSlider.setBounds(bandNineSlider.getX() + bandNineSlider.getWidth() + 10, topMargin + 14, 192, 192);
    inSlider.setLookAndFeel(&otherLookAndFeel);
    
    addAndMakeVisible(inSliderTrack);
    inSliderTrackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, IN_ID, inSliderTrack);
    inSliderTrack.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    inSliderTrack.setTextBoxStyle(Slider::TextBoxAbove, false, 96, 24);
    inSliderTrack.setTextValueSuffix(" dB In");
    inSliderTrack.setRange(0, 12, .1);
    inSliderTrack.addListener(this);
    inSliderTrack.setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    inSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 1));
    inSliderTrack.setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
    inSliderTrack.setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, 0));
    inSliderTrack.setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, 0));
    inSliderTrack.setBounds(bandNineSlider.getX() + bandNineSlider.getWidth() + 24, topMargin, 164, 164);
    
    //Out Slider
    addAndMakeVisible(outSlider);
    outSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, OUT_ID, outSlider);
    outSlider.setRange(-12, 12, .1);
    outSlider.setTextValueSuffix(" db Out");
    outSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    outSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 96, 32);
    outSlider.setColour(Slider::backgroundColourId, Colour::fromFloatRGBA(0, 0, 0, .75));
    outSlider.setColour(Slider::trackColourId, Colour::fromFloatRGBA(0, 0, 0, .75));
    outSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(1, 1, 1, 1));
    outSlider.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    outSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    outSlider.setBounds(bandNineSlider.getX() + bandNineSlider.getWidth() + 10, topMargin + 200, 192, 192);
    outSlider.setLookAndFeel(&otherLookAndFeel);
    
    addAndMakeVisible(outSliderTrack);
    outSliderTrackValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, OUT_ID, outSliderTrack);
    outSliderTrack.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    outSliderTrack.setTextBoxStyle(Slider::TextBoxAbove, false, 96, 24);
    outSliderTrack.setTextValueSuffix(" dB Out");
    outSliderTrack.setRange(-12, 12, .1);
    outSliderTrack.addListener(this);
    outSliderTrack.setColour(0x1001700, Colour::fromFloatRGBA(0, 0, 0, 0));
    outSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    outSliderTrack.setColour(0x1001300, Colour::fromFloatRGBA(1, 1, 1, 0));
    outSliderTrack.setColour(0x1001312, Colour::fromFloatRGBA(0, 0, 0, 0));
    outSliderTrack.setColour(0x1001311, Colour::fromFloatRGBA(.2, .77, 1, 0));
    outSliderTrack.setBounds(bandNineSlider.getX() + bandNineSlider.getWidth() + 24, topMargin + 186, 164, 164);
    
    addAndMakeVisible(lowPassToggle);
    lowPassAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, LOWPASS_ID, lowPassToggle);
    lowPassToggle.setButtonText("Low-Pass");
    lowPassToggle.setClickingTogglesState(true);
    lowPassToggle.addListener(this);
    lowPassToggle.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    lowPassToggle.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    lowPassToggle.setBounds(leftMargin + 6, bandOneMinus.getY(), 82, 32);
    if (processor.treeState.getParameter(LOWPASS_ID)){
        lowPassToggle.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        lowPassToggle.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(highPassToggle);
    highPassAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, HIGHPASS_ID, highPassToggle);
    highPassToggle.setButtonText("High-Pass");
    highPassToggle.setClickingTogglesState(true);
    highPassToggle.addListener(this);
    highPassToggle.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    highPassToggle.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    highPassToggle.setBounds(leftMargin + 6, bandOneWide.getY(), 82, 32);
    if (processor.treeState.getParameter(HIGHPASS_ID)){
        highPassToggle.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        highPassToggle.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(phaseToggle);
    phaseAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, PHASE_ID, phaseToggle);
    phaseToggle.setButtonText("Phase");
    phaseToggle.setClickingTogglesState(true);
    phaseToggle.addListener(this);
    phaseToggle.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    phaseToggle.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    phaseToggle.setBounds(leftMargin + 6, bandOneNarrow.getY(), 82, 32);
    if (processor.treeState.getParameter(PHASE_ID)){
        phaseToggle.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        phaseToggle.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(resetButton);
    resetButton.setButtonText("Default");
    resetButton.addListener(this);
    resetButton.setBounds(leftMargin + 6, lowPassToggle.getY() - 42, 82, 32);
    setTextColors();
    
    
    
    
}

Viator_graphic_eqAudioProcessorEditor::~Viator_graphic_eqAudioProcessorEditor()
{
}

void Viator_graphic_eqAudioProcessorEditor::setTextColors(){
    
    for(auto i = 0; i < bandSliders.size(); i++){
        bandSliders[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0.5));
        bandSliders[i]->setColour(Slider::backgroundColourId, Colour::fromFloatRGBA(.05, .05, .05, 1));
        bandSliders[i]->setColour(Slider::trackColourId, Colour::fromFloatRGBA(.05, .05, .05, 1));
        plusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        plusButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
        minusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        minusButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
        wideButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        wideButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
        narrowButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        narrowButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    for (auto i = 0; i < toggleButtons.size(); i++){
        toggleButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        toggleButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    resetButton.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
    resetButton.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    inSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    outSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 0));
    
}

//==============================================================================
void Viator_graphic_eqAudioProcessorEditor::paint (Graphics& g)
{
    //g.fillAll(Colour::fromFloatRGBA(0.14f, 0.16f, 0.2f, 1.0f));
    Image background = ImageCache::getFromMemory (BinaryData::graphicEQBackground_png, BinaryData::graphicEQBackground_pngSize);
    g.drawImageAt (background, 0, 0);
}

void Viator_graphic_eqAudioProcessorEditor::resized()
{
    
}

void Viator_graphic_eqAudioProcessorEditor::buttonClicked(Button *button)
{
    
    for (auto i = 0; i < plusButtons.size(); i++){
        if (button == plusButtons[i]){
            bandSliders[i]->setValue(bandSliders[i]->getValue() + 1);
            if (plusButtons[i]->getToggleState() == 1){
                plusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
            }
        }
    }
    
    for (auto i = 0; i < minusButtons.size(); i++){
        if (button == minusButtons[i]){
            bandSliders[i]->setValue(bandSliders[i]->getValue() - 1);
            if (minusButtons[i]->getToggleState() == 1){
                minusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
            }
        }
    }
    
    for(auto i = 0; i < wideButtons.size(); i++){
        if (button == wideButtons[i]){
            if(narrowButtons[i]->getToggleState() == 1){
                narrowButtons[i]->triggerClick();
                
            }
        }
    }
    
    for(auto i = 0; i < narrowButtons.size(); i++){
        if (button == narrowButtons[i]){
            if(wideButtons[i]->getToggleState() == 1){
                wideButtons[i]->triggerClick();
                
            }
        }
    }
    
    for(auto i = 0; i < toggleButtons.size(); i++){
            if (button == toggleButtons[i]){
                toggleButtons[i]->setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
                toggleButtons[i]->setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
            }
    }
    
    if (button == &resetButton){
        for (auto i = 0; i < bandSliders.size(); i++) {
            bandSliders[i]->setValue(0);
        }
    }
}

void Viator_graphic_eqAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if (slider == &inSliderTrack){
        inSlider.setValue(inSliderTrack.getValue());
    } else if (slider == &outSliderTrack){
        outSlider.setValue(outSliderTrack.getValue());
    }
    
}


