/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define subSliderId "subSlider"
#define subSliderName "SubSlider"

#define bassSliderId "bassSlider"
#define bassSliderName "BassSlider"

#define earthSliderId "earthSlider"
#define earthSliderName "EarthSlider"

#define fogSliderId "fogSlider"
#define fogSliderName "FogSlider"

#define stingSliderId "stingSlider"
#define stingSliderName "StingSlider"

#define airSliderId "airSlider"
#define airSliderName "AirSlider"

//==============================================================================
/**
*/
class Viator_element_eqAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Viator_element_eqAudioProcessor();
    ~Viator_element_eqAudioProcessor();

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
    
    float lastSampleRate;
    
    std::vector<dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>>*> filters;
    
private:
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>>
    subFilter, bassFilter, earthFilter, fogFilter, stingFilter, airFilter;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Viator_element_eqAudioProcessor)
};
