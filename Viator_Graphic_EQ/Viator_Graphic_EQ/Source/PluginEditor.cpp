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
    
    plusButtons.push_back(&bandOnePlus);
    minusButtons.push_back(&bandOneMinus);
    wideButtons.push_back(&bandOneWide);
    narrowButtons.push_back(&bandOneNarrow);
    plusButtons.push_back(&bandTwoPlus);
    minusButtons.push_back(&bandTwoMinus);
    wideButtons.push_back(&bandTwoWide);
    narrowButtons.push_back(&bandTwoNarrow);
    plusButtons.push_back(&bandThreePlus);
    minusButtons.push_back(&bandThreeMinus);
    wideButtons.push_back(&bandThreeWide);
    narrowButtons.push_back(&bandThreeNarrow);
    plusButtons.push_back(&bandFourPlus);
    minusButtons.push_back(&bandFourMinus);
    wideButtons.push_back(&bandFourWide);
    narrowButtons.push_back(&bandFourNarrow);
    plusButtons.push_back(&bandFivePlus);
    minusButtons.push_back(&bandFiveMinus);
    wideButtons.push_back(&bandFiveWide);
    narrowButtons.push_back(&bandFiveNarrow);
    plusButtons.push_back(&bandSixPlus);
    minusButtons.push_back(&bandSixMinus);
    wideButtons.push_back(&bandSixWide);
    narrowButtons.push_back(&bandSixNarrow);
    plusButtons.push_back(&bandSevenPlus);
    minusButtons.push_back(&bandSevenMinus);
    wideButtons.push_back(&bandSevenWide);
    narrowButtons.push_back(&bandSevenNarrow);
    plusButtons.push_back(&bandEightPlus);
    minusButtons.push_back(&bandEightMinus);
    wideButtons.push_back(&bandEightWide);
    narrowButtons.push_back(&bandEightNarrow);
    plusButtons.push_back(&bandNinePlus);
    minusButtons.push_back(&bandNineMinus);
    wideButtons.push_back(&bandNineWide);
    narrowButtons.push_back(&bandNineNarrow);
    
    toggleButtons.push_back(&lowPassToggle);
    toggleButtons.push_back(&highPassToggle);
    toggleButtons.push_back(&phaseToggle);
    
    bandSliders.push_back(&bandOneSlider);
    bandSliders.push_back(&bandTwoSlider);
    bandSliders.push_back(&bandThreeSlider);
    bandSliders.push_back(&bandFourSlider);
    bandSliders.push_back(&bandFiveSlider);
    bandSliders.push_back(&bandSixSlider);
    bandSliders.push_back(&bandSevenSlider);
    bandSliders.push_back(&bandEightSlider);
    bandSliders.push_back(&bandNineSlider);
    
    //Band One
    //Slider
    addAndMakeVisible(bandOneSlider);
    bandOneSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_ONE_ID, bandOneSlider);
    bandOneSlider.setRange(-18, 18, .5);
    bandOneSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandOneSlider.setTextValueSuffix(" db\n 60 Hz");
    bandOneSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandOneSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandOneSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandOneSlider.setBounds(leftMargin + 146, topMargin, 68, 256);
    
    //Gain Buttons
    addAndMakeVisible(bandOneMinus);
    bandOneMinus.addListener(this);
    bandOneMinus.setButtonText("-");
    bandOneMinus.setToggleState(false, dontSendNotification);
    bandOneMinus.setBounds(leftMargin + 152, 280, 28, 30);
    
    addAndMakeVisible(bandOnePlus);
    bandOnePlus.addListener(this);
    bandOnePlus.setButtonText("+");
    bandOnePlus.setToggleState(false, dontSendNotification);
    bandOnePlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandOnePlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandOnePlus.setBounds(bandOneMinus.getX() + bandOneMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandOneWide);
    bandOneWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDONEWIDE_ID, bandOneWide);
    bandOneWide.addListener(this);
    bandOneWide.setButtonText("Wide");
    bandOneWide.setClickingTogglesState(true);
    bandOneWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
    bandOneWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandOneWide.setBounds(leftMargin + 152, bandOneMinus.getY() + bandOneMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDONEWIDE_ID)){
        bandOneWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandOneWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandOneNarrow);
    bandOneNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDONENARROW_ID, bandOneNarrow);
    bandOneNarrow.addListener(this);
    bandOneNarrow.setButtonText("Slim");
    bandOneNarrow.setClickingTogglesState(true);
    bandOneNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandOneNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandOneNarrow.setBounds(leftMargin + 152, bandOneWide.getY() + bandOneWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDONENARROW_ID)){
        bandOneNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandOneNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Two
    addAndMakeVisible(bandTwoSlider);
    bandTwoSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_TWO_ID, bandTwoSlider);
    bandTwoSlider.setRange(-18, 18, .5);
    bandTwoSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandTwoSlider.setTextValueSuffix(" db\n 125 Hz");
    bandTwoSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandTwoSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandTwoSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandTwoSlider.setBounds(bandOneSlider.getX() + bandOneSlider.getWidth() + 24, topMargin, 64, 256);
    
    //Gain Buttons
    addAndMakeVisible(bandTwoMinus);
    bandTwoMinus.addListener(this);
    bandTwoMinus.setButtonText("-");
    bandTwoMinus.setToggleState(false, dontSendNotification);
    bandTwoMinus.setBounds(bandOneSlider.getX() + bandOneSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandTwoPlus);
    bandTwoPlus.addListener(this);
    bandTwoPlus.setButtonText("+");
    bandTwoPlus.setToggleState(false, dontSendNotification);
    bandTwoPlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandTwoPlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandTwoPlus.setBounds(bandTwoMinus.getX() + bandTwoMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandTwoWide);
    bandTwoWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTWOWIDE_ID, bandTwoWide);
    bandTwoWide.addListener(this);
    bandTwoWide.setButtonText("Wide");
    bandTwoWide.setClickingTogglesState(true);
    bandTwoWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandTwoWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandTwoWide.setBounds(bandTwoMinus.getX(), bandTwoMinus.getY() + bandTwoMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDTWOWIDE_ID)){
        bandTwoWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandTwoWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandTwoNarrow);
    bandTwoNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTWONARROW_ID, bandTwoNarrow);
    bandTwoNarrow.addListener(this);
    bandTwoNarrow.setButtonText("Slim");
    bandTwoNarrow.setClickingTogglesState(true);
    bandTwoNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandTwoNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandTwoNarrow.setBounds(bandTwoMinus.getX(), bandTwoWide.getY() + bandTwoWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDTWONARROW_ID)){
        bandTwoNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandTwoNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Three
    addAndMakeVisible(bandThreeSlider);
    bandThreeSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_THREE_ID, bandThreeSlider);
    bandThreeSlider.setRange(-18, 18, .5);
    bandThreeSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandThreeSlider.setTextValueSuffix(" db\n 250 Hz");
    bandThreeSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandThreeSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandThreeSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandThreeSlider.setBounds(bandTwoSlider.getX() + bandTwoSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandThreeMinus);
    bandThreeMinus.addListener(this);
    bandThreeMinus.setButtonText("-");
    bandThreeMinus.setToggleState(false, dontSendNotification);
    bandThreeMinus.setBounds(bandTwoSlider.getX() + bandTwoSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandThreePlus);
    bandThreePlus.addListener(this);
    bandThreePlus.setButtonText("+");
    bandThreePlus.setToggleState(false, dontSendNotification);
    bandThreePlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandThreePlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandThreePlus.setBounds(bandThreeMinus.getX() + bandThreeMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandThreeWide);
    bandThreeWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTHREEWIDE_ID, bandThreeWide);
    bandThreeWide.addListener(this);
    bandThreeWide.setButtonText("Wide");
    bandThreeWide.setClickingTogglesState(true);
    bandThreeWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandThreeWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandThreeWide.setBounds(bandThreeMinus.getX(), bandThreeMinus.getY() + bandThreeMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDTHREEWIDE_ID)){
        bandThreeWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandThreeWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandThreeNarrow);
    bandThreeNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDTHREENARROW_ID, bandThreeNarrow);
    bandThreeNarrow.addListener(this);
    bandThreeNarrow.setButtonText("Slim");
    bandThreeNarrow.setClickingTogglesState(true);
    bandThreeNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandThreeNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandThreeNarrow.setBounds(bandThreeMinus.getX(), bandThreeWide.getY() + bandThreeWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDTHREENARROW_ID)){
        bandThreeNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandThreeNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Four
    addAndMakeVisible(bandFourSlider);
    bandFourSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_FOUR_ID, bandFourSlider);
    bandFourSlider.setRange(-18, 18, .5);
    bandFourSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandFourSlider.setTextValueSuffix(" db\n 500 Hz");
    bandFourSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandFourSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandFourSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandFourSlider.setBounds(bandThreeSlider.getX() + bandThreeSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandFourMinus);
    bandFourMinus.addListener(this);
    bandFourMinus.setButtonText("-");
    bandFourMinus.setToggleState(false, dontSendNotification);
    bandFourMinus.setBounds(bandThreeSlider.getX() + bandThreeSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandFourPlus);
    bandFourPlus.addListener(this);
    bandFourPlus.setButtonText("+");
    bandFourPlus.setToggleState(false, dontSendNotification);
    bandFourPlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
    bandFourPlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandFourPlus.setBounds(bandFourMinus.getX() + bandFourMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandFourWide);
    bandFourWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFOURWIDE_ID, bandFourWide);
    bandFourWide.addListener(this);
    bandFourWide.setButtonText("Wide");
    bandFourWide.setClickingTogglesState(true);
    bandFourWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandFourWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandFourWide.setBounds(bandFourMinus.getX(), bandFourMinus.getY() + bandFourMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDFOURWIDE_ID)){
        bandFourWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandFourWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandFourNarrow);
    bandFourNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFOURNARROW_ID, bandFourNarrow);
    bandFourNarrow.addListener(this);
    bandFourNarrow.setButtonText("Slim");
    bandFourNarrow.setClickingTogglesState(true);
    bandFourNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandFourNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandFourNarrow.setBounds(bandFourMinus.getX(), bandFourWide.getY() + bandFourWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDFOURNARROW_ID)){
        bandFourNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandFourNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Five
    addAndMakeVisible(bandFiveSlider);
    bandFiveSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_FIVE_ID, bandFiveSlider);
    bandFiveSlider.setRange(-18, 18, .5);
    bandFiveSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandFiveSlider.setTextValueSuffix(" db\n 1K Hz");
    bandFiveSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandFiveSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandFiveSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandFiveSlider.setBounds(bandFourSlider.getX() + bandFourSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandFiveMinus);
    bandFiveMinus.addListener(this);
    bandFiveMinus.setButtonText("-");
    bandFiveMinus.setToggleState(false, dontSendNotification);
    bandFiveMinus.setBounds(bandFourSlider.getX() + bandFourSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandFivePlus);
    bandFivePlus.addListener(this);
    bandFivePlus.setButtonText("+");
    bandFivePlus.setToggleState(false, dontSendNotification);
    bandFivePlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandFivePlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandFivePlus.setBounds(bandFiveMinus.getX() + bandFiveMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandFiveWide);
    bandFiveWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFIVEWIDE_ID, bandFiveWide);
    bandFiveWide.addListener(this);
    bandFiveWide.setButtonText("Wide");
    bandFiveWide.setClickingTogglesState(true);
    bandFiveWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandFiveWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandFiveWide.setBounds(bandFiveMinus.getX(), bandFiveMinus.getY() + bandFiveMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDFIVEWIDE_ID)){
        bandFiveWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandFiveWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandFiveNarrow);
    bandFiveNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDFIVENARROW_ID, bandFiveNarrow);
    bandFiveNarrow.addListener(this);
    bandFiveNarrow.setButtonText("Slim");
    bandFiveNarrow.setClickingTogglesState(true);
    bandFiveNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandFiveNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandFiveNarrow.setBounds(bandFiveMinus.getX(), bandFiveWide.getY() + bandFiveWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDFIVENARROW_ID)){
        bandFiveNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandFiveNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Six
    addAndMakeVisible(bandSixSlider);
    bandSixSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_SIX_ID, bandSixSlider);
    bandSixSlider.setRange(-18, 18, .5);
    bandSixSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandSixSlider.setTextValueSuffix(" db\n 2K Hz");
    bandSixSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandSixSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandSixSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandSixSlider.setBounds(bandFiveSlider.getX() + bandFiveSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandSixMinus);
    bandSixMinus.addListener(this);
    bandSixMinus.setButtonText("-");
    bandSixMinus.setToggleState(false, dontSendNotification);
    bandSixMinus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSixMinus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSixMinus.setBounds(bandFiveSlider.getX() + bandFiveSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandSixPlus);
    bandSixPlus.addListener(this);
    bandSixPlus.setButtonText("+");
    bandSixPlus.setToggleState(false, dontSendNotification);
    bandSixPlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSixPlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSixPlus.setBounds(bandSixMinus.getX() + bandSixMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandSixWide);
    bandSixWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSIXWIDE_ID, bandSixWide);
    bandSixWide.addListener(this);
    bandSixWide.setButtonText("Wide");
    bandSixWide.setClickingTogglesState(true);
    bandSixWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSixWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSixWide.setBounds(bandSixMinus.getX(), bandSixMinus.getY() + bandSixMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDSIXWIDE_ID)){
        bandSixWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandSixWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandSixNarrow);
    bandSixNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSIXNARROW_ID, bandSixNarrow);
    bandSixNarrow.addListener(this);
    bandSixNarrow.setButtonText("Slim");
    bandSixNarrow.setClickingTogglesState(true);
    bandSixNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSixNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSixNarrow.setBounds(bandSixMinus.getX(), bandSixWide.getY() + bandSixWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDSIXNARROW_ID)){
        bandSixNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandSixNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Seven
    addAndMakeVisible(bandSevenSlider);
    bandSevenSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_SEVEN_ID, bandSevenSlider);
    bandSevenSlider.setRange(-18, 18, .5);
    bandSevenSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandSevenSlider.setTextValueSuffix(" db\n 4K Hz");
    bandSevenSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandSevenSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandSevenSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandSevenSlider.setBounds(bandSixSlider.getX() + bandSixSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandSevenMinus);
    bandSevenMinus.addListener(this);
    bandSevenMinus.setButtonText("-");
    bandSevenMinus.setToggleState(false, dontSendNotification);
    bandSevenMinus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSevenMinus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSevenMinus.setBounds(bandSixSlider.getX() + bandSixSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandSevenPlus);
    bandSevenPlus.addListener(this);
    bandSevenPlus.setButtonText("+");
    bandSevenPlus.setToggleState(false, dontSendNotification);
    bandSevenPlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSevenPlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSevenPlus.setBounds(bandSevenMinus.getX() + bandSevenMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandSevenWide);
    bandSevenWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSEVENWIDE_ID, bandSevenWide);
    bandSevenWide.addListener(this);
    bandSevenWide.setButtonText("Wide");
    bandSevenWide.setClickingTogglesState(true);
    bandSevenWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSevenWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSevenWide.setBounds(bandSevenMinus.getX(), bandSevenMinus.getY() + bandSevenMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDSEVENWIDE_ID)){
        bandSevenWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandSevenWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandSevenNarrow);
    bandSevenNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDSEVENNARROW_ID, bandSevenNarrow);
    bandSevenNarrow.addListener(this);
    bandSevenNarrow.setButtonText("Slim");
    bandSevenNarrow.setClickingTogglesState(true);
    bandSevenNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandSevenNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandSevenNarrow.setBounds(bandSevenMinus.getX(), bandSevenWide.getY() + bandSevenWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDSEVENNARROW_ID)){
        bandSevenNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandSevenNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Eight
    addAndMakeVisible(bandEightSlider);
    bandEightSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_EIGHT_ID, bandEightSlider);
    bandEightSlider.setRange(-18, 18, .5);
    bandEightSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandEightSlider.setTextValueSuffix(" db\n 8K Hz");
    bandEightSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandEightSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandEightSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandEightSlider.setBounds(bandSevenSlider.getX() + bandSevenSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandEightMinus);
    bandEightMinus.addListener(this);
    bandEightMinus.setButtonText("-");
    bandEightMinus.setToggleState(false, dontSendNotification);
    bandEightMinus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandEightMinus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandEightMinus.setBounds(bandSevenSlider.getX() + bandSevenSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandEightPlus);
    bandEightPlus.addListener(this);
    bandEightPlus.setButtonText("+");
    bandEightPlus.setToggleState(false, dontSendNotification);
    bandEightPlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandEightPlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandEightPlus.setBounds(bandEightMinus.getX() + bandEightMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandEightWide);
    bandEightWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDEIGHTWIDE_ID, bandEightWide);
    bandEightWide.addListener(this);
    bandEightWide.setButtonText("Wide");
    bandEightWide.setClickingTogglesState(true);
    bandEightWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandEightWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandEightWide.setBounds(bandEightMinus.getX(), bandEightMinus.getY() + bandEightMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDEIGHTWIDE_ID)){
        bandEightWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandEightWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandEightNarrow);
    bandEightNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDEIGHTNARROW_ID, bandEightNarrow);
    bandEightNarrow.addListener(this);
    bandEightNarrow.setButtonText("Slim");
    bandEightNarrow.setClickingTogglesState(true);
    bandEightNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandEightNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandEightNarrow.setBounds(bandEightMinus.getX(), bandEightWide.getY() + bandEightWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDEIGHTNARROW_ID)){
        bandEightNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandEightNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    //Slider Nine
    addAndMakeVisible(bandNineSlider);
    bandNineSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, BAND_SLIDER_NINE_ID, bandNineSlider);
    bandNineSlider.setRange(-18, 18, .5);
    bandNineSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    bandNineSlider.setTextValueSuffix(" db\n 16K Hz");
    bandNineSlider.setTextBoxStyle(Slider::TextBoxAbove, false, 64, 32);
    bandNineSlider.setColour(Slider::thumbColourId, Colour::fromFloatRGBA(00.75, 0.76, 0.77, 1.000));
    bandNineSlider.setColour(0x1001700, Colour::fromFloatRGBA(0.862, 0.862, 0.862, 0)); //text box border
    bandNineSlider.setBounds(bandEightSlider.getX() + bandEightSlider.getWidth() + 24, topMargin, 64, 256);
    
    addAndMakeVisible(bandNineMinus);
    bandNineMinus.addListener(this);
    bandNineMinus.setButtonText("-");
    bandNineMinus.setToggleState(false, dontSendNotification);
    bandNineMinus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandNineMinus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandNineMinus.setBounds(bandEightSlider.getX() + bandEightSlider.getWidth() + 4 + 24, 280, 28, 30);
    
    addAndMakeVisible(bandNinePlus);
    bandNinePlus.addListener(this);
    bandNinePlus.setButtonText("+");
    bandNinePlus.setToggleState(false, dontSendNotification);
    bandNinePlus.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandNinePlus.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandNinePlus.setBounds(bandNineMinus.getX() + bandNineMinus.getWidth(), 280, 28, 30);
    
    //Wide and Narrow Toggles
    addAndMakeVisible(bandNineWide);
    bandNineWideAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDNINEWIDE_ID, bandNineWide);
    bandNineWide.addListener(this);
    bandNineWide.setButtonText("Wide");
    bandNineWide.setClickingTogglesState(true);
    bandNineWide.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandNineWide.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandNineWide.setBounds(bandNineMinus.getX(), bandNineMinus.getY() + bandNineMinus.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDNINEWIDE_ID)){
        bandNineWide.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandNineWide.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    }
    
    addAndMakeVisible(bandNineNarrow);
    bandNineNarrowAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, BANDNINENARROW_ID, bandNineNarrow);
    bandNineNarrow.addListener(this);
    bandNineNarrow.setButtonText("Slim");
    bandNineNarrow.setClickingTogglesState(true);
    bandNineNarrow.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .75));
    bandNineNarrow.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    bandNineNarrow.setBounds(bandNineMinus.getX(), bandNineWide.getY() + bandNineWide.getHeight() + 12, 56, 30);
    if (processor.treeState.getParameter(BANDNINENARROW_ID)){
        bandNineNarrow.setColour(0x1000103, Colour::fromFloatRGBA(.2, .77, 1, .75));
        bandNineNarrow.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
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
    outSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, 1));
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
    }
    
    for (auto i = 0; i < plusButtons.size(); i++){
        plusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        plusButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    for (auto i = 0; i < minusButtons.size(); i++){
        minusButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        minusButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    for (auto i = 0; i < wideButtons.size(); i++){
        wideButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        wideButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    for (auto i = 0; i < narrowButtons.size(); i++){
        narrowButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        narrowButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    for (auto i = 0; i < toggleButtons.size(); i++){
        toggleButtons[i]->setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
        toggleButtons[i]->setColour(0x1000100, Colour::fromFloatRGBA(1, 1, 1, 0));
    }
    
    resetButton.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .5));
    resetButton.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    inSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, .5));
    outSliderTrack.setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, .5));
    
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


