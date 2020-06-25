/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

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
    
    
    auto subSliderParam = std::make_unique<AudioParameterFloat>(subSliderId, subSliderName, -12, 12, 0);
    
    params.push_back(std::move(subSliderParam));
    
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
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
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

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
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
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Viator_element_eqAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Viator_element_eqAudioProcessor();
}
