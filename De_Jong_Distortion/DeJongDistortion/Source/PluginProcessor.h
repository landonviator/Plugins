/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#define In_Slider_Id "Input"
#define In_Slider_Name "Input"
#define A_Slider_Id "A"
#define A_Slider_Name "A"
#define B_Slider_Id "B"
#define B_Slider_Name "B"
#define C_Slider_Id "C"
#define C_Slider_Name "C"
#define D_Slider_Id "D"
#define D_Slider_Name "D"
#define Out_Slider_Id "Output"
#define Out_Slider_Name "Output"
#define Link_Id "Link"
#define Link_Name "Link"

//==============================================================================
/**
*/
class DeJongDistortionAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    DeJongDistortionAudioProcessor();
    ~DeJongDistortionAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    AudioProcessorValueTreeState treeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    double nextLeftDejongSample {0};
    double nextRightDejongSample {0};

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeJongDistortionAudioProcessor)
};
