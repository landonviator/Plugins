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
Viator_element_eqAudioProcessor::Viator_element_eqAudioProcessor()
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
subFilter(dsp::IIR::Coefficients<float>::makeLowShelf(44100, 80, 1.0, 1.0)),
bassFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 100, 1.0, 1.0)),
earthFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 245, 0.75, 1.0)),
fogFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 835, 0.8, 1.0)),
stingFilter(dsp::IIR::Coefficients<float>::makePeakFilter(44100, 400, 2.0, 1.0)),
airFilter(dsp::IIR::Coefficients<float>::makeHighShelf(44100, 6000, 1.0, 1.0))
#endif
{
}

Viator_element_eqAudioProcessor::~Viator_element_eqAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout Viator_element_eqAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    params.reserve(6);
    
    
    auto subSliderParam = std::make_unique<AudioParameterFloat>(subSliderId, subSliderName, -12, 12, 0);
    auto bassSliderParam = std::make_unique<AudioParameterFloat>(bassSliderId, bassSliderName, -12, 12, 0);
    auto earthSliderParam = std::make_unique<AudioParameterFloat>(earthSliderId, earthSliderName, -12, 12, 0);
    auto fogSliderParam = std::make_unique<AudioParameterFloat>(fogSliderId, fogSliderName, -12, 12, 0);
    auto stingSliderParam = std::make_unique<AudioParameterFloat>(stingSliderId, stingSliderName, -12, 12, 0);
    auto airSliderParam = std::make_unique<AudioParameterFloat>(airSliderId, airSliderName, -12, 12, 0);
    
    params.push_back(std::move(subSliderParam));
    params.push_back(std::move(bassSliderParam));
    params.push_back(std::move(earthSliderParam));
    params.push_back(std::move(fogSliderParam));
    params.push_back(std::move(stingSliderParam));
    params.push_back(std::move(airSliderParam));
    
    return { params.begin(), params.end() };
}

//==============================================================================
const String Viator_element_eqAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Viator_element_eqAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Viator_element_eqAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Viator_element_eqAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Viator_element_eqAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Viator_element_eqAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Viator_element_eqAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Viator_element_eqAudioProcessor::setCurrentProgram (int index)
{
}

const String Viator_element_eqAudioProcessor::getProgramName (int index)
{
    return {};
}

void Viator_element_eqAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Viator_element_eqAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lastSampleRate = sampleRate;
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    
    //Make and optimize a vector for the filters
    filters.reserve(6);
    filters = {
        &subFilter, &bassFilter, &earthFilter, &fogFilter, &stingFilter, &airFilter
    };
    
    for (size_t i = 0; i < filters.size(); i++){
        filters[i]->prepare(spec);
        filters[i]->reset();
    }
}

void Viator_element_eqAudioProcessor::releaseResources()
{
    

}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Viator_element_eqAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Viator_element_eqAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    auto* subGain = treeState.getRawParameterValue(subSliderId);
    auto subGainScaled = pow(10, (*subGain * 0.05f));
    auto* bassGain = treeState.getRawParameterValue(bassSliderId);
    auto bassGainScaled = pow(10, (*bassGain * 0.05f));
    auto* earthGain = treeState.getRawParameterValue(earthSliderId);
    auto earthGainScaled = pow(10, (*earthGain * 0.05f));
    auto* fogGain = treeState.getRawParameterValue(fogSliderId);
    auto fogGainScaled = pow(10, (*fogGain * 0.05f));
    auto* stingGain = treeState.getRawParameterValue(stingSliderId);
    auto stingGainScaled = pow(10, (*stingGain * 0.05f));
    auto* airGain = treeState.getRawParameterValue(airSliderId);
    auto airGainScaled = pow(10, (*airGain * 0.05f));
    
    dsp::AudioBlock<float> block (buffer);

    updateSubFilter(subGainScaled);
    subFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBassFilter(bassGainScaled);
    bassFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateEarthFilter(earthGainScaled);
    earthFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateFogFilter(fogGainScaled);
    fogFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateStingFilter(stingGainScaled);
    stingFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateAirFilter(airGainScaled);
    airFilter.process(dsp::ProcessContextReplacing<float>(block));
    
//    std::thread parallelFilterOne(&Viator_element_eqAudioProcessor::callFilterGroupOne, this, subGainScaled, block, bassGainScaled);
//   // parallelFilterOne.join();
//    std::thread parallelFilterTwo(&Viator_element_eqAudioProcessor::callFilterGroupTwo, this, earthGainScaled, block, fogGainScaled);
//    //parallelFilterTwo.join();
//    std::thread parallelFilterThree(&Viator_element_eqAudioProcessor::callFilterGroupThree, this, stingGainScaled, block, airGainScaled);
//    //parallelFilterThree.join();
    

    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
           


        }
    }
    
//        parallelFilterOne.join();
//        parallelFilterTwo.join();
//        parallelFilterThree.join();
}

void Viator_element_eqAudioProcessor::updateSubFilter(float gain){
    
    *subFilter.state = *dsp::IIR::Coefficients<float>::makeLowShelf(lastSampleRate, 80.0, 1.0, gain);
}

void Viator_element_eqAudioProcessor::updateBassFilter(float gain){
    
    *bassFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 100.0, 1.0, gain);
}

void Viator_element_eqAudioProcessor::updateEarthFilter(float gain){
    
    *earthFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 245.0, 0.75, gain);
}

void Viator_element_eqAudioProcessor::updateFogFilter(float gain){
    
    *fogFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 835.0, 0.8, gain);
}

void Viator_element_eqAudioProcessor::updateStingFilter(float gain){
    
    *stingFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, 4000.0, 2.0, gain);
}

void Viator_element_eqAudioProcessor::updateAirFilter(float gain){
    
    *airFilter.state = *dsp::IIR::Coefficients<float>::makeHighShelf(lastSampleRate, 6000.0, 1.0, gain);
}

void Viator_element_eqAudioProcessor::callFilterGroupOne(double gain1, dsp::AudioBlock<float> block, double gain2){
    updateSubFilter(gain1);
    subFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateBassFilter(gain2);
    bassFilter.process(dsp::ProcessContextReplacing<float>(block));
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
}

void Viator_element_eqAudioProcessor::callFilterGroupTwo(double gain1, dsp::AudioBlock<float> block, double gain2){
    updateEarthFilter(gain1);
    earthFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateFogFilter(gain2);
    fogFilter.process(dsp::ProcessContextReplacing<float>(block));
}

void Viator_element_eqAudioProcessor::callFilterGroupThree(double gain1, dsp::AudioBlock<float> block, double gain2){
    updateStingFilter(gain1);
    stingFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateAirFilter(gain2);
    airFilter.process(dsp::ProcessContextReplacing<float>(block));
}

void Viator_element_eqAudioProcessor::joinThreads(Thread thread1, Thread thread2, Thread thread3){
    thread1.stopThread(1000);
    thread2.stopThread(1000);
    thread3.stopThread(1000);

}

//==============================================================================
bool Viator_element_eqAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Viator_element_eqAudioProcessor::createEditor()
{
    return new Viator_element_eqAudioProcessorEditor (*this);
}

//==============================================================================
void Viator_element_eqAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void Viator_element_eqAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new Viator_element_eqAudioProcessor();
}
