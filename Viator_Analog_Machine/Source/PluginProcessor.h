/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define TRIM_SLIDER_ID "Trim"
#define TRIM_SLIDER_NAME "Trim"
#define IN_GAIN_SLIDER_ID "Input"
#define IN_GAIN_SLIDER_NAME "Input"
#define OUT_GAIN_SLIDER_ID "Output"
#define OUT_GAIN_SLIDER_NAME "Output"
#define HIGHPASS_SLIDER_ID "High-Pass"
#define HIGHPASS_SLIDER_NAME "High-Pass"
#define LOWPASS_SLIDER_ID "Low-Pass"
#define LOWPASS_SLIDER_NAME "Low-Pass"
#define SATURATE_SLIDER_ID "Saturation"
#define SATURATE_SLIDER_NAME "Saturation"
#define PHASE_ID "Phase"
#define PHASE_NAME "Phase"

//==============================================================================
/**
*/
class AnalogMachineAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AnalogMachineAudioProcessor();
    ~AnalogMachineAudioProcessor();

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
    double applySaturation(double input, double drive, double inGain, int rawSaturate, int rawInput);
    void updateLowPassFilter(float freq);
    void updateHighPassFilter(float freq);

    AudioProcessorValueTreeState treeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    double piDivisor = 2 / M_PI;
    float lastSampleRate;
    int phaseValue {0};
    
private:
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> lowPassFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> highPassFilter;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnalogMachineAudioProcessor)
};
