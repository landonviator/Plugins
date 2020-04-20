/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AnalogMachineAudioProcessor::AnalogMachineAudioProcessor()
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
highPassFilter(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20, 0.1f))
#endif
{
}

AnalogMachineAudioProcessor::~AnalogMachineAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout AnalogMachineAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    
    auto trimParam = std::make_unique<AudioParameterFloat>(TRIM_SLIDER_ID, TRIM_SLIDER_NAME, -48.0f, 48.0f, 0.0f);
    auto inGainParam = std::make_unique<AudioParameterFloat>(IN_GAIN_SLIDER_ID, IN_GAIN_SLIDER_NAME, 0.0f, 9.0f, 0.0f);
    auto highPassParam = std::make_unique<AudioParameterFloat>(HIGHPASS_SLIDER_ID, HIGHPASS_SLIDER_NAME, 20.0f, 500.0f, 0.0f);
    auto lowPassParam = std::make_unique<AudioParameterFloat>(LOWPASS_SLIDER_ID, LOWPASS_SLIDER_NAME, 10000, 20000, 20000);
    auto saturateParam = std::make_unique<AudioParameterFloat>(SATURATE_SLIDER_ID, SATURATE_SLIDER_NAME, 0.0f, 24.0f, 0.0f);
    auto phaseParam = std::make_unique<AudioParameterBool>(PHASE_ID, PHASE_NAME, false);
    
    params.push_back(std::move(trimParam));
    params.push_back(std::move(inGainParam));
    params.push_back(std::move(highPassParam));
    params.push_back(std::move(lowPassParam));
    params.push_back(std::move(saturateParam));
    params.push_back(std::move(phaseParam));
    return { params.begin(), params.end() };
}

//==============================================================================
const String AnalogMachineAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AnalogMachineAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AnalogMachineAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AnalogMachineAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AnalogMachineAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AnalogMachineAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AnalogMachineAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AnalogMachineAudioProcessor::setCurrentProgram (int index)
{
}

const String AnalogMachineAudioProcessor::getProgramName (int index)
{
    return {};
}

void AnalogMachineAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AnalogMachineAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
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
}

void AnalogMachineAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AnalogMachineAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void AnalogMachineAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    auto* rawTrim = treeState.getRawParameterValue(TRIM_SLIDER_ID);
    auto* rawInGain = treeState.getRawParameterValue(IN_GAIN_SLIDER_ID);
    auto* rawHighPass = treeState.getRawParameterValue(HIGHPASS_SLIDER_ID);
    auto* rawLowPass = treeState.getRawParameterValue(LOWPASS_SLIDER_ID);
    auto* rawSaturate = treeState.getRawParameterValue(SATURATE_SLIDER_ID);
    auto* rawPhase = treeState.getRawParameterValue(PHASE_ID);
    
    auto trimParam = pow(10, *rawTrim * .05);
    auto inParam = pow(10, *rawInGain * .05);
    auto saturateParam = pow(10, *rawSaturate * .08);
    
    if (*rawPhase == 1){
        phaseValue = -1;
    } else {
        phaseValue = 1;
    }
    
    dsp::AudioBlock<float> block (buffer);

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    updateLowPassFilter(*rawLowPass);
    lowPassFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateHighPassFilter(*rawHighPass);
    highPassFilter.process(dsp::ProcessContextReplacing<float>(block));

    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        
        auto* channelData = buffer.getWritePointer (channel);
        auto* inputData = buffer.getReadPointer(channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
            channelData[sample] = (applySaturation(inputData[sample] * inParam, saturateParam, inParam, *rawSaturate, *rawInGain) * phaseValue) * trimParam;
        }
    }
}

double AnalogMachineAudioProcessor::applySaturation(double input, double drive, double inGain, int rawSaturate, int rawInput){
    auto compensate = ((rawSaturate + 6) + (rawInput + 1)) * -1;
    return (atan(drive * input - pow(input, 3)) * pow(10, compensate * .05)) * 2.25;
}

void AnalogMachineAudioProcessor::updateLowPassFilter(float freq){
    *lowPassFilter.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, freq);
}
void AnalogMachineAudioProcessor::updateHighPassFilter(float freq){
    *highPassFilter.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, freq);
}

//==============================================================================
bool AnalogMachineAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AnalogMachineAudioProcessor::createEditor()
{
    return new AnalogMachineAudioProcessorEditor (*this);
}

//==============================================================================
void AnalogMachineAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void AnalogMachineAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new AnalogMachineAudioProcessor();
}
