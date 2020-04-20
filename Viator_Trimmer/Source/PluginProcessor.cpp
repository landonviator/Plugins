/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LpvtrimmerAudioProcessor::LpvtrimmerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
treeState (*this, nullptr, "PARAMETER", createParameterLayout())

#endif
{
}

LpvtrimmerAudioProcessor::~LpvtrimmerAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout LpvtrimmerAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    
    auto inGainParam = std::make_unique<AudioParameterFloat>(INGAIN_ID, INGAIN_NAME, -60.0f, 24.0f, 0.0f);
    auto phaseParam = std::make_unique<AudioParameterBool>(PHASE_ID, PHASE_NAME, false);
    
    params.push_back(std::move(inGainParam));
    params.push_back(std::move(phaseParam));
    return { params.begin(), params.end() };
}

//==============================================================================
const String LpvtrimmerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool LpvtrimmerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool LpvtrimmerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool LpvtrimmerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double LpvtrimmerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int LpvtrimmerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int LpvtrimmerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void LpvtrimmerAudioProcessor::setCurrentProgram (int index)
{
}

const String LpvtrimmerAudioProcessor::getProgramName (int index)
{
    return {};
}

void LpvtrimmerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void LpvtrimmerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
}

void LpvtrimmerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool LpvtrimmerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void LpvtrimmerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    auto* inGain = treeState.getRawParameterValue(INGAIN_ID);
    auto* rawPhase = treeState.getRawParameterValue(PHASE_ID);

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        
        auto* inBuffer = (buffer.getReadPointer (channel));
        auto* outBuffer = buffer.getWritePointer (channel);
        
        double inGainScaled = pow(10, *inGain * 0.05);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            double input {inBuffer[sample]};
            
                outBuffer[sample] = (applyGain(input, inGainScaled) * applyPhase(*rawPhase));
            }
        }
    }
//==============================================================================

double LpvtrimmerAudioProcessor::applyGain(double &input, double &gain){
    return input * gain;
}

int LpvtrimmerAudioProcessor::applyPhase(int p){
    return (-1 -1) * ((p - 0) / (1 - 0)) + 1; //scaling function
}

//==============================================================================
bool LpvtrimmerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* LpvtrimmerAudioProcessor::createEditor()
{
    return new LpvtrimmerAudioProcessorEditor (*this);
}

//==============================================================================
void LpvtrimmerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void LpvtrimmerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new LpvtrimmerAudioProcessor();
}
