/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define inputSliderId "input"
#define inputSliderName "Input"

#define saturationSliderId "saturation"
#define saturationSliderName "Saturation"

#define outputSliderId "output"
#define outputSliderName "Output"

#define saturationModelId "voice"
#define saturationModelName "Voice"

//==============================================================================
/**
*/
class Viator_clippy_boiAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Viator_clippy_boiAudioProcessor();
    ~Viator_clippy_boiAudioProcessor();

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
    
    double applySoftClip(double input, double drive);
    double applyHardClip(double input, double drive);
    
    double piDivisor = 2/M_PI;

    AudioProcessorValueTreeState treeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
private:
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Viator_clippy_boiAudioProcessor)
};
