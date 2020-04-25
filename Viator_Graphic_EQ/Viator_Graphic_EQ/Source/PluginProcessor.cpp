/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <thread>

//==============================================================================
Viator_graphic_eqAudioProcessor::Viator_graphic_eqAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
treeState (*this, nullptr, "PARAMETER", createParameterLayout()),
lowPassFilter(dsp::IIR::Coefficients<float>::makeLowPass(44100, 20000, 0.1f)),
highPassFilter(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20000, 0.1f)),
bandOneFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 30, .6, 1)),
bandTwoFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 60, .6, 1)),
bandThreeFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 125, .6, 1)),
bandFourFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 500, .6, 1)),
bandFiveFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 1000, .6, 1)),
bandSixFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 2000, .6, 1)),
bandSevenFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 4000, .6, 1)),
bandEightFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 8000, .6, 1)),
bandNineFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 16000, .6, 1))
#endif
{
}

Viator_graphic_eqAudioProcessor::~Viator_graphic_eqAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout Viator_graphic_eqAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    
    
    auto bandSliderOneParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_ONE_ID, BAND_SLIDER_ONE_NAME, -18, 18, 0);
    auto bandOneWideParam = std::make_unique<AudioParameterBool>(BANDONEWIDE_ID, BANDONEWIDE_NAME, false);
    auto bandOneNarrowParam = std::make_unique<AudioParameterBool>(BANDONENARROW_ID, BANDONENARROW_NAME, false);
    
    auto bandSliderTwoParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_TWO_ID, BAND_SLIDER_TWO_NAME, -18, 18, 0);
    auto bandTwoWideParam = std::make_unique<AudioParameterBool>(BANDTWOWIDE_ID, BANDTWOWIDE_NAME, false);
    auto bandTwoNarrowParam = std::make_unique<AudioParameterBool>(BANDTWONARROW_ID, BANDTWONARROW_NAME, false);
    
    auto bandSliderThreeParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_THREE_ID, BAND_SLIDER_THREE_NAME, -18, 18, 0);
    auto bandThreeWideParam = std::make_unique<AudioParameterBool>(BANDTHREEWIDE_ID, BANDTHREEWIDE_NAME, false);
    auto bandThreeNarrowParam = std::make_unique<AudioParameterBool>(BANDTHREENARROW_ID, BANDTHREENARROW_NAME, false);
    
    auto bandSliderFourParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_FOUR_ID, BAND_SLIDER_FOUR_NAME, -18, 18, 0);
    auto bandFourWideParam = std::make_unique<AudioParameterBool>(BANDFOURWIDE_ID, BANDFOURWIDE_NAME, false);
    auto bandFourNarrowParam = std::make_unique<AudioParameterBool>(BANDFOURNARROW_ID, BANDFOURNARROW_NAME, false);
    
    auto bandSliderFiveParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_FIVE_ID, BAND_SLIDER_FIVE_NAME, -18, 18, 0);
    auto bandFiveWideParam = std::make_unique<AudioParameterBool>(BANDFIVEWIDE_ID, BANDFIVEWIDE_NAME, false);
    auto bandFiveNarrowParam = std::make_unique<AudioParameterBool>(BANDFIVENARROW_ID, BANDFIVENARROW_NAME, false);
    
    auto bandSliderSixParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_SIX_ID, BAND_SLIDER_SIX_NAME, -18, 18, 0);
    auto bandSixWideParam = std::make_unique<AudioParameterBool>(BANDSIXWIDE_ID, BANDSIXWIDE_NAME, false);
    auto bandSixNarrowParam = std::make_unique<AudioParameterBool>(BANDSIXNARROW_ID, BANDSIXNARROW_NAME, false);
    
    auto bandSliderSevenParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_SEVEN_ID, BAND_SLIDER_SEVEN_NAME, -18, 18, 0);
    auto bandSevenWideParam = std::make_unique<AudioParameterBool>(BANDSEVENWIDE_ID, BANDSEVENWIDE_NAME, false);
    auto bandSevenNarrowParam = std::make_unique<AudioParameterBool>(BANDSEVENNARROW_ID, BANDSEVENNARROW_NAME, false);
    
    auto bandSliderEightParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_EIGHT_ID, BAND_SLIDER_EIGHT_NAME, -18, 18, 0);
    auto bandEightWideParam = std::make_unique<AudioParameterBool>(BANDEIGHTWIDE_ID, BANDEIGHTWIDE_NAME, false);
    auto bandEightNarrowParam = std::make_unique<AudioParameterBool>(BANDEIGHTNARROW_ID, BANDEIGHTNARROW_NAME, false);
    
    auto bandSliderNineParam = std::make_unique<AudioParameterInt>(BAND_SLIDER_NINE_ID, BAND_SLIDER_NINE_NAME, -18, 18, 0);
    auto bandNineWideParam = std::make_unique<AudioParameterBool>(BANDNINEWIDE_ID, BANDNINEWIDE_NAME, false);
    auto bandNineNarrowParam = std::make_unique<AudioParameterBool>(BANDNINENARROW_ID, BANDNINENARROW_NAME, false);
    
    auto inParam = std::make_unique<AudioParameterFloat>(IN_ID, IN_NAME, 0, 12, 0);
    auto outParam = std::make_unique<AudioParameterFloat>(OUT_ID, OUT_NAME, -12, 12, 0);
    auto phaseParam = std::make_unique<AudioParameterBool>(PHASE_ID, PHASE_NAME, false);
    auto lowPassParam = std::make_unique<AudioParameterBool>(LOWPASS_ID, LOWPASS_NAME, false);
    auto highPassParam = std::make_unique<AudioParameterBool>(HIGHPASS_ID, HIGHPASS_NAME, false);
    
    params.push_back(std::move(bandSliderOneParam));
    params.push_back(std::move(bandOneWideParam));
    params.push_back(std::move(bandOneNarrowParam));
    
    params.push_back(std::move(bandSliderTwoParam));
    params.push_back(std::move(bandTwoWideParam));
    params.push_back(std::move(bandTwoNarrowParam));
    
    params.push_back(std::move(bandSliderThreeParam));
    params.push_back(std::move(bandThreeWideParam));
    params.push_back(std::move(bandThreeNarrowParam));
    
    params.push_back(std::move(bandSliderFourParam));
    params.push_back(std::move(bandFourWideParam));
    params.push_back(std::move(bandFourNarrowParam));
    
    params.push_back(std::move(bandSliderFiveParam));
    params.push_back(std::move(bandFiveWideParam));
    params.push_back(std::move(bandFiveNarrowParam));
    
    params.push_back(std::move(bandSliderSixParam));
    params.push_back(std::move(bandSixWideParam));
    params.push_back(std::move(bandSixNarrowParam));
    
    params.push_back(std::move(bandSliderSevenParam));
    params.push_back(std::move(bandSevenWideParam));
    params.push_back(std::move(bandSevenNarrowParam));
    
    params.push_back(std::move(bandSliderEightParam));
    params.push_back(std::move(bandEightWideParam));
    params.push_back(std::move(bandEightNarrowParam));
    
    params.push_back(std::move(bandSliderNineParam));
    params.push_back(std::move(bandNineWideParam));
    params.push_back(std::move(bandNineNarrowParam));
    
    params.push_back(std::move(inParam));
    params.push_back(std::move(outParam));
    params.push_back(std::move(phaseParam));
    params.push_back(std::move(lowPassParam));
    params.push_back(std::move(highPassParam));
    return { params.begin(), params.end() };
}

//==============================================================================
const String Viator_graphic_eqAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Viator_graphic_eqAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Viator_graphic_eqAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Viator_graphic_eqAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Viator_graphic_eqAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Viator_graphic_eqAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Viator_graphic_eqAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Viator_graphic_eqAudioProcessor::setCurrentProgram (int index)
{
}

const String Viator_graphic_eqAudioProcessor::getProgramName (int index)
{
    return {};
}

void Viator_graphic_eqAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Viator_graphic_eqAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lastSampleRate = sampleRate;
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    
    lowPassFilter.prepare(spec);
    lowPassFilter.reset();
    
    highPassFilter.prepare(spec);
    highPassFilter.reset();
    
    bandOneFilter.prepare(spec);
    bandOneFilter.reset();
    bandTwoFilter.prepare(spec);
    bandTwoFilter.reset();
    bandThreeFilter.prepare(spec);
    bandThreeFilter.reset();
    bandFourFilter.prepare(spec);
    bandFourFilter.reset();
    bandFiveFilter.prepare(spec);
    bandFiveFilter.reset();
    bandSixFilter.prepare(spec);
    bandSixFilter.reset();
    bandSevenFilter.prepare(spec);
    bandSevenFilter.reset();
    bandEightFilter.prepare(spec);
    bandEightFilter.reset();
    bandNineFilter.prepare(spec);
    bandNineFilter.reset();
}

void Viator_graphic_eqAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Viator_graphic_eqAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Viator_graphic_eqAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    
    auto* rawInput = treeState.getRawParameterValue(IN_ID);
    auto* rawOutput = treeState.getRawParameterValue(OUT_ID);
    auto* rawPhase = treeState.getRawParameterValue(PHASE_ID);
    auto* rawLowPass = treeState.getRawParameterValue(LOWPASS_ID);
    auto* rawHighPass = treeState.getRawParameterValue(HIGHPASS_ID);
    auto* rawBandOneGain = treeState.getRawParameterValue(BAND_SLIDER_ONE_ID);
    auto* rawBandTwoGain = treeState.getRawParameterValue(BAND_SLIDER_TWO_ID);
    auto* rawBandThreeGain = treeState.getRawParameterValue(BAND_SLIDER_THREE_ID);
    auto* rawBandFourGain = treeState.getRawParameterValue(BAND_SLIDER_FOUR_ID);
    auto* rawBandFiveGain = treeState.getRawParameterValue(BAND_SLIDER_FIVE_ID);
    auto* rawBandSixGain = treeState.getRawParameterValue(BAND_SLIDER_SIX_ID);
    auto* rawBandSevenGain = treeState.getRawParameterValue(BAND_SLIDER_SEVEN_ID);
    auto* rawBandEightGain = treeState.getRawParameterValue(BAND_SLIDER_EIGHT_ID);
    auto* rawBandNineGain = treeState.getRawParameterValue(BAND_SLIDER_NINE_ID);
    
    
    double bandOneGain = pow(10, *rawBandOneGain * .05);
    double bandTwoGain = pow(10, *rawBandTwoGain * .05);
    double bandThreeGain = pow(10, *rawBandThreeGain * .05);
    double bandFourGain = pow(10, *rawBandFourGain * .05);
    double bandFiveGain = pow(10, *rawBandFiveGain * .05);
    double bandSixGain = pow(10, *rawBandSixGain * .05);
    double bandSevenGain = pow(10, *rawBandSevenGain * .05);
    double bandEightGain = pow(10, *rawBandEightGain * .05);
    double bandNineGain = pow(10, *rawBandNineGain * .05);
    
    double inGainScaled = pow(10, *rawInput * 0.05f);
    double outGainScaled = pow(10, *rawOutput * 0.05f);
    double outCompesation = pow(inGainScaled, -.9);
    
    
    
    dsp::AudioBlock<float> block (buffer);
    if (*rawLowPass == 1){
        updateLowPassFilter(15000);
        lowPassFilter.process(dsp::ProcessContextReplacing<float>(block));
    } if (*rawHighPass == 1){
        updateHighPassFilter(100);
        highPassFilter.process(dsp::ProcessContextReplacing<float>(block));
    }
    
    std::thread parallelFilterOne(&Viator_graphic_eqAudioProcessor::callFilterGroupOne, this, bandOneGain, block, bandTwoGain);
    std::thread parallelFilterTwo(&Viator_graphic_eqAudioProcessor::callFilterGroupTwo, this, bandThreeGain, block, bandFourGain);
    std::thread parallelFilterThree(&::Viator_graphic_eqAudioProcessor::callFilterGroupThree, this, bandFiveGain, block, bandSixGain);
    std::thread parallelFilterFour(&Viator_graphic_eqAudioProcessor::callFilterGroupFour, this, bandSevenGain, block, bandEightGain, bandNineGain);
    
    

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        auto* inputData = buffer.getReadPointer(channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
            double input = inputData[sample] * inGainScaled * applyPhase(*rawPhase);
            channelData[sample] = applyOutput(saturation(input), outGainScaled) * outCompesation;
        }
    }
    
    parallelFilterOne.join();
    parallelFilterTwo.join();
    parallelFilterThree.join();
    parallelFilterFour.join();
    
}

double Viator_graphic_eqAudioProcessor::saturation(double signal){
    return piDivisor * atan(signal * 2) * .8;
}

double Viator_graphic_eqAudioProcessor::applyOutput(double signal, double gain){
    return (signal * gain);
}

int Viator_graphic_eqAudioProcessor::applyPhase(int p){
    return (-1 -1) * ((p - 0) / (1 - 0)) + 1; //scaling function
}

void Viator_graphic_eqAudioProcessor::updateLowPassFilter(float freq){
    *lowPassFilter.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, freq);
}
void Viator_graphic_eqAudioProcessor::updateHighPassFilter(float freq){
    *highPassFilter.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, freq);
}

void Viator_graphic_eqAudioProcessor::updateBandOneFilter(float gain, float q){
    
    auto* bandOneWide = treeState.getRawParameterValue(BANDONEWIDE_ID);
    auto* bandOneNarrow = treeState.getRawParameterValue(BANDONENARROW_ID);
    
    if (*bandOneWide){
        q = .3;
    } else if (*bandOneNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandOneFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 60, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandTwoFilter(float gain, float q){
    
    auto* bandTwoWide = treeState.getRawParameterValue(BANDTWOWIDE_ID);
    auto* bandTwoNarrow = treeState.getRawParameterValue(BANDTWONARROW_ID);
    
    if (*bandTwoWide){
        q = .3;
    } else if (*bandTwoNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    
    *bandTwoFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 125, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandThreeFilter(float gain, float q){
    
    auto* bandThreeWide = treeState.getRawParameterValue(BANDTHREEWIDE_ID);
    auto* bandThreeNarrow = treeState.getRawParameterValue(BANDTHREENARROW_ID);
    
    if (*bandThreeWide){
        q = .3;
    } else if (*bandThreeNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandThreeFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 250, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandFourFilter(float gain, float q){
    
    auto* bandFourWide = treeState.getRawParameterValue(BANDFOURWIDE_ID);
    auto* bandFourNarrow = treeState.getRawParameterValue(BANDFOURNARROW_ID);
    
    if (*bandFourWide){
        q = .3;
    } else if (*bandFourNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandFourFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 500, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandFiveFilter(float gain, float q){
    auto* bandFiveWide = treeState.getRawParameterValue(BANDFIVEWIDE_ID);
    auto* bandFiveNarrow = treeState.getRawParameterValue(BANDFIVENARROW_ID);
    
    if (*bandFiveWide){
        q = .3;
    } else if (*bandFiveNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandFiveFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 1000, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandSixFilter(float gain, float q){
    
    auto* bandSixWide = treeState.getRawParameterValue(BANDSIXWIDE_ID);
    auto* bandSixNarrow = treeState.getRawParameterValue(BANDSIXNARROW_ID);
    
    if (*bandSixWide){
        q = .3;
    } else if (*bandSixNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandSixFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 2000, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandSevenFilter(float gain, float q){
    
    auto* bandSevenWide = treeState.getRawParameterValue(BANDSEVENWIDE_ID);
    auto* bandSevenNarrow = treeState.getRawParameterValue(BANDSEVENNARROW_ID);
    
    if (*bandSevenWide){
        q = .3;
    } else if (*bandSevenNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandSevenFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 4000, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandEightFilter(float gain, float q){
    
    auto* bandEightWide = treeState.getRawParameterValue(BANDEIGHTWIDE_ID);
    auto* bandEightNarrow = treeState.getRawParameterValue(BANDEIGHTNARROW_ID);
    
    if (*bandEightWide){
        q = .3;
    } else if (*bandEightNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandEightFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 8000, q, gain);
}

void Viator_graphic_eqAudioProcessor::updateBandNineFilter(float gain, float q){
    
    auto* bandNineWide = treeState.getRawParameterValue(BANDNINEWIDE_ID);
    auto* bandNineNarrow = treeState.getRawParameterValue(BANDNINENARROW_ID);
    
    if (*bandNineWide){
        q = .3;
    } else if (*bandNineNarrow){
        q = 6;
    } else {
        q = .6;
    }
    
    *bandNineFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 16000, q, gain);
}

void Viator_graphic_eqAudioProcessor::callFilterGroupOne(double gain1, dsp::AudioBlock<float> block, double gain2){
    
    updateBandOneFilter(gain1, 0.6f);
    bandOneFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBandTwoFilter(gain2, 0.6f);
    bandTwoFilter.process(dsp::ProcessContextReplacing<float>(block));
    
}

void Viator_graphic_eqAudioProcessor::callFilterGroupTwo(double gain1, dsp::AudioBlock<float> block, double gain2){
    
    updateBandThreeFilter(gain1, 0.6f);
    bandThreeFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBandFourFilter(gain2, .6);
    bandFourFilter.process(dsp::ProcessContextReplacing<float>(block));
    
}

void Viator_graphic_eqAudioProcessor::callFilterGroupThree(double gain1, dsp::AudioBlock<float> block, double gain2){
    
    updateBandFiveFilter(gain1, 0.6f);
    bandFiveFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBandSixFilter(gain2, 0.6f);
    bandSixFilter.process(dsp::ProcessContextReplacing<float>(block));
    
}

void Viator_graphic_eqAudioProcessor::callFilterGroupFour(double gain1, dsp::AudioBlock<float> block, double gain2, double gain3){
    
    updateBandSevenFilter(gain1, 0.6f);
    bandSevenFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBandEightFilter(gain2, 0.6f);
    bandEightFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBandNineFilter(gain3, 0.6f);
    bandNineFilter.process(dsp::ProcessContextReplacing<float>(block));
    
}



//==============================================================================
bool Viator_graphic_eqAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Viator_graphic_eqAudioProcessor::createEditor()
{
    return new Viator_graphic_eqAudioProcessorEditor (*this);
}

//==============================================================================
void Viator_graphic_eqAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void Viator_graphic_eqAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    ValueTree tree = ValueTree::readFromData (data, size_t (sizeInBytes));
    if (tree.isValid()) {
        treeState.state = tree;
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Viator_graphic_eqAudioProcessor();
}
