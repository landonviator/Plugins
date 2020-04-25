/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define BAND_SLIDER_ONE_ID "60Hz"
#define BAND_SLIDER_ONE_NAME "60Hz"
#define BANDONEWIDE_ID "60Hz Wide"
#define BANDONEWIDE_NAME "60Hz Wide"
#define BANDONENARROW_ID "60Hz Narrow"
#define BANDONENARROW_NAME "60Hz Narrow"

#define BAND_SLIDER_TWO_ID "125Hz"
#define BAND_SLIDER_TWO_NAME "125Hz"
#define BANDTWOWIDE_ID "125Hz Wide"
#define BANDTWOWIDE_NAME "125Hz Wide"
#define BANDTWONARROW_ID "125Hz Narrow"
#define BANDTWONARROW_NAME "125Hz Narrow"

#define BAND_SLIDER_THREE_ID "250Hx"
#define BAND_SLIDER_THREE_NAME "250Hx"
#define BANDTHREEWIDE_ID "250Hx Wide"
#define BANDTHREEWIDE_NAME "250Hx Wide"
#define BANDTHREENARROW_ID "250Hx Narrow"
#define BANDTHREENARROW_NAME "250Hx Narrow"

#define BAND_SLIDER_FOUR_ID "500Hz"
#define BAND_SLIDER_FOUR_NAME "500Hz"
#define BANDFOURWIDE_ID "500Hz Wide"
#define BANDFOURWIDE_NAME "500Hz Wide"
#define BANDFOURNARROW_ID "500Hz Narrow"
#define BANDFOURNARROW_NAME "500Hz Narrow"

#define BAND_SLIDER_FIVE_ID "1kHz"
#define BAND_SLIDER_FIVE_NAME "1kHz"
#define BANDFIVEWIDE_ID "1kHz Wide"
#define BANDFIVEWIDE_NAME "1kHz Wide"
#define BANDFIVENARROW_ID "1kHz Narrow"
#define BANDFIVENARROW_NAME "1kHz Narrow"

#define BAND_SLIDER_SIX_ID "2kHz"
#define BAND_SLIDER_SIX_NAME "2kHz"
#define BANDSIXWIDE_ID "2kHz Wide"
#define BANDSIXWIDE_NAME "2kHz Wide"
#define BANDSIXNARROW_ID "2kHz Narrow"
#define BANDSIXNARROW_NAME "2kHz Narrow"

#define BAND_SLIDER_SEVEN_ID "4kHz"
#define BAND_SLIDER_SEVEN_NAME "4kHz"
#define BANDSEVENWIDE_ID "4kHz Wide"
#define BANDSEVENWIDE_NAME "4kHz Wide"
#define BANDSEVENNARROW_ID "4kHz Narrow"
#define BANDSEVENNARROW_NAME "4kHz Narrow"

#define BAND_SLIDER_EIGHT_ID "8kHz"
#define BAND_SLIDER_EIGHT_NAME "8kHz"
#define BANDEIGHTWIDE_ID "8kHz Wide"
#define BANDEIGHTWIDE_NAME "8kHz Wide"
#define BANDEIGHTNARROW_ID "8kHz Narrow"
#define BANDEIGHTNARROW_NAME "8kHz Narrow"

#define BAND_SLIDER_NINE_ID "16kHz"
#define BAND_SLIDER_NINE_NAME "16kHz"
#define BANDNINEWIDE_ID "16kHz Wide"
#define BANDNINEWIDE_NAME "16kHz Wide"
#define BANDNINENARROW_ID "16kHz Narrow"
#define BANDNINENARROW_NAME "16kHz Narrow"

#define IN_ID "In"
#define IN_NAME "In"

#define INTRACK_ID ""
#define INTRACK_NAME ""

#define OUT_ID "Out"
#define OUT_NAME "Out"

#define OUTTRACK_ID ""
#define OUTTRACK_NAME ""

#define PHASE_ID "Phase"
#define PHASE_NAME "Phase"

#define LOWPASS_ID "Low-Pass"
#define LOWPASS_NAME "Low-Pass"

#define HIGHPASS_ID "High-Pass"
#define HIGHPASS_NAME "High-Pass"


//==============================================================================
/**
*/
class Viator_graphic_eqAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Viator_graphic_eqAudioProcessor();
    ~Viator_graphic_eqAudioProcessor();

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
    
    double saturation (double signal);
    double applyOutput (double signal, double gain);
    int applyPhase(int p);
    
    double piDivisor = 2 / M_PI;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    void updateLowPassFilter(float freq);
    void updateHighPassFilter(float freq);
    void updateBandOneFilter(float gain, float q);
    void updateBandTwoFilter(float gain, float q);
    void updateBandThreeFilter(float gain, float q);
    void updateBandFourFilter(float gain, float q);
    void updateBandFiveFilter(float gain, float q);
    void updateBandSixFilter(float gain, float q);
    void updateBandSevenFilter(float gain, float q);
    void updateBandEightFilter(float gain, float q);
    void updateBandNineFilter(float gain, float q);
    
      void callFilterGroupOne(double gain1, dsp::AudioBlock<float> block, double gain2);
      void callFilterGroupTwo(double gain1, dsp::AudioBlock<float> block, double gain2);
      void callFilterGroupThree(double gain1, dsp::AudioBlock<float> block, double gain2);
      void callFilterGroupFour(double gain1, dsp::AudioBlock<float> block, double gain2, double gain3);
    
    float lastSampleRate;

    AudioProcessorValueTreeState treeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
private:
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> lowPassFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> highPassFilter;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandOneFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandTwoFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandThreeFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandFourFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandFiveFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandSixFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandSevenFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandEightFilter;
    dsp::ProcessorDuplicator<dsp::IIR::Filter<float>, dsp::IIR::Coefficients<float>> bandNineFilter;

    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Viator_graphic_eqAudioProcessor)
};
