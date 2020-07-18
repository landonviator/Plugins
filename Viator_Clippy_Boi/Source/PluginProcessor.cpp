/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Viator_clippy_boiAudioProcessor::Viator_clippy_boiAudioProcessor()
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

Viator_clippy_boiAudioProcessor::~Viator_clippy_boiAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout Viator_clippy_boiAudioProcessor::createParameterLayout(){
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    params.reserve(6);
    
    auto inputSliderParam = std::make_unique<AudioParameterFloat>(inputSliderId, inputSliderName, -24, 24, 0);
    auto saturationSliderParam = std::make_unique<AudioParameterFloat>(saturationSliderId, saturationSliderName, 0, 24, 0);
    auto outputSliderParam = std::make_unique<AudioParameterFloat>(outputSliderId, outputSliderName, -24, 24, 0);
    auto saturationModelParam = std::make_unique<AudioParameterInt>(saturationModelId, saturationModelName, 0, 1, 0);
    
    params.push_back(std::move(inputSliderParam));
    params.push_back(std::move(saturationSliderParam));
    params.push_back(std::move(outputSliderParam));
    params.push_back(std::move(saturationModelParam));
    
    return { params.begin(), params.end() };
}

//==============================================================================
const String Viator_clippy_boiAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Viator_clippy_boiAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Viator_clippy_boiAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Viator_clippy_boiAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Viator_clippy_boiAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Viator_clippy_boiAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Viator_clippy_boiAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Viator_clippy_boiAudioProcessor::setCurrentProgram (int index)
{
}

const String Viator_clippy_boiAudioProcessor::getProgramName (int index)
{
    return {};
}

void Viator_clippy_boiAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Viator_clippy_boiAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Viator_clippy_boiAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Viator_clippy_boiAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void Viator_clippy_boiAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    auto* rawVoice = treeState.getRawParameterValue(saturationModelId);
    auto* rawInput = treeState.getRawParameterValue(inputSliderId);
    auto* rawSaturation = treeState.getRawParameterValue(saturationSliderId);
    auto* rawOutput = treeState.getRawParameterValue(outputSliderId);

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* inputData = buffer.getReadPointer (channel);
        auto* outputData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            if (*rawVoice == 0){
                outputData[sample] = applySoftClip(inputData[sample], pow(10, *rawSaturation * 0.05));
            } else {
                outputData[sample] = applyHardClip(inputData[sample], pow(10, *rawSaturation * 0.05));
            }
        }
    }
}


double Viator_clippy_boiAudioProcessor::applySoftClip(double input, double drive){
    return piDivisor * atan(input * pow(10, (drive * 0.05)));
}

double Viator_clippy_boiAudioProcessor::applyHardClip(double input, double drive){
    if (input > 1){
        input = 1;
    } else if (input < -1){
        input = -1;
    }
    
    return 1.5 * (input * drive) - .5 * pow((input * drive), 3);
}
//==============================================================================
bool Viator_clippy_boiAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Viator_clippy_boiAudioProcessor::createEditor()
{
    return new Viator_clippy_boiAudioProcessorEditor (*this);
}

//==============================================================================
void Viator_clippy_boiAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void Viator_clippy_boiAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new Viator_clippy_boiAudioProcessor();
}
