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
#define HIGHCUT_ID "highcut"
#define HIGHCUT_NAME "Highcut"
#define LOWCUT_ID "lowcut"
#define LOWCUT_NAME "Lowcut"
#define SATURATE_ID "saturate"
#define SATURATE_NAME "Saturate"
#define OUT_ID "out"
#define OUT_NAME "Out"
#define FORCE_ID "force"
#define FORCE_NAME "Force"
#define AUTO_ID "auto"
#define AUTO_NAME "Auto"

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
    void updateLowPassFilter(float freq);
    void updateLowPassFilter2(float freq);
    void updateLowPassFilter3(float freq);
    void updateHighPassFilter(float freq);
    void updateHighPassFilter2(float freq);
    void updateHighPassFilter3(float freq);
    double applySaturation(double signal, double drive, int forced);
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
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> lowPassFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> lowPassFilter2;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> lowPassFilter3;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> highPassFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> highPassFilter2;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> highPassFilter3;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LpvtrimmerAudioProcessor)
};
