/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "../JuceLibraryCode/JuceHeader.h"
#define INGAIN_ID "inputgain"
#define INGAIN_NAME "inputGain"
#define MINUS_ID "minus"
#define MINUS_NAME "Minus"
#define PLUS_ID "plus"
#define PLUS_NAME "Plus"
#define PHASE_ID "phase"
#define PHASE_NAME "Phase"

//==============================================================================
/**
*/



class LpvtrimmerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    LpvtrimmerAudioProcessor();
    ~LpvtrimmerAudioProcessor();

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
    double applyGain(double &input, double &gain);
    int applyPhase(int p);
    
    AudioProcessorValueTreeState treeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    bool phaseState {false};
    bool buttonState {false};
    bool autoCheck;
    double piDivisor = 2 / M_PI;
    
    float lastSampleRate;

private:
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LpvtrimmerAudioProcessor)
};
