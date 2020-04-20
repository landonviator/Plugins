/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ViatorConsoleAudioProcessor::ViatorConsoleAudioProcessor()
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
lowPassFilter2(dsp::IIR::Coefficients<float>::makeLowPass(44100, 20000, 0.1f)),
lowPassFilter3(dsp::IIR::Coefficients<float>::makeLowPass(44100, 20000, 0.1f)),
highPassFilter(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20000, 0.1f)),
highPassFilter2(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20000, 0.1f)),
highPassFilter3(dsp::IIR::Coefficients<float>::makeHighPass(44100, 20000, 0.1f))
#endif
{
}

AudioProcessorValueTreeState::ParameterLayout ViatorConsoleAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    
    auto inGainParam = std::make_unique<AudioParameterFloat>(INGAIN_ID, INGAIN_NAME, -60.0f, 24.0f, 0.0f);
    auto highCutParam = std::make_unique<AudioParameterInt>(HIGHCUT_ID, HIGHCUT_NAME, 20, 20000, 20000);
    auto lowCutParam = std::make_unique<AudioParameterInt>(LOWCUT_ID, LOWCUT_NAME, 20, 20000, 30);
    auto saturateParam = std::make_unique<AudioParameterFloat>(SATURATE_ID, SATURATE_NAME, 0, 24, 0);
    auto outParam = std::make_unique<AudioParameterFloat>(OUT_ID, OUT_NAME, -60, 24, 0);
    auto phaseParam = std::make_unique<AudioParameterBool>(PHASE_ID, PHASE_NAME, false);
    auto forceParam = std::make_unique<AudioParameterBool>(FORCE_ID, FORCE_NAME, false);
    auto autoParam = std::make_unique<AudioParameterBool>(AUTO_ID, AUTO_NAME, false);
    
    params.push_back(std::move(inGainParam));
    params.push_back(std::move(highCutParam));
    params.push_back(std::move(lowCutParam));
    params.push_back(std::move(saturateParam));
    params.push_back(std::move(outParam));
    params.push_back(std::move(phaseParam));
    params.push_back(std::move(forceParam));
    params.push_back(std::move(autoParam));
    
    return { params.begin(), params.end() };
}

ViatorConsoleAudioProcessor::~ViatorConsoleAudioProcessor()
{
}

//==============================================================================
const String ViatorConsoleAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ViatorConsoleAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ViatorConsoleAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ViatorConsoleAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ViatorConsoleAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ViatorConsoleAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ViatorConsoleAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ViatorConsoleAudioProcessor::setCurrentProgram (int index)
{
}

const String ViatorConsoleAudioProcessor::getProgramName (int index)
{
    return {};
}

void ViatorConsoleAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ViatorConsoleAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lastSampleRate = sampleRate;
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    
    lowPassFilter.prepare(spec);
    lowPassFilter.reset();
    lowPassFilter2.prepare(spec);
    lowPassFilter2.reset();
    lowPassFilter3.prepare(spec);
    lowPassFilter3.reset();
    highPassFilter.prepare(spec);
    highPassFilter.reset();
    highPassFilter2.prepare(spec);
    highPassFilter2.reset();
    highPassFilter3.prepare(spec);
    highPassFilter3.reset();
}

void ViatorConsoleAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ViatorConsoleAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void ViatorConsoleAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    auto* inGain = treeState.getRawParameterValue(INGAIN_ID);
    auto* rawPhase = treeState.getRawParameterValue(PHASE_ID);
    auto* highCut = treeState.getRawParameterValue(HIGHCUT_ID);
    auto* lowCut = treeState.getRawParameterValue(LOWCUT_ID);
    auto* saturation = treeState.getRawParameterValue(SATURATE_ID);
    auto* outGain = treeState.getRawParameterValue(OUT_ID);
    auto* forceParam = treeState.getRawParameterValue(FORCE_ID);
    auto* autoParam = treeState.getRawParameterValue(AUTO_ID);
    
    dsp::AudioBlock<float> block (buffer);
    updateLowPassFilter(*highCut);
    lowPassFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateLowPassFilter2(*highCut);
    lowPassFilter2.process(dsp::ProcessContextReplacing<float>(block));
    updateLowPassFilter3(*highCut);
    lowPassFilter3.process(dsp::ProcessContextReplacing<float>(block));
    updateHighPassFilter(*lowCut);
    highPassFilter.process(dsp::ProcessContextReplacing<float>(block));
    updateHighPassFilter2(*lowCut);
    highPassFilter2.process(dsp::ProcessContextReplacing<float>(block));
    updateHighPassFilter3(*lowCut);
    highPassFilter3.process(dsp::ProcessContextReplacing<float>(block));
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        
        
        auto* inBuffer = (buffer.getReadPointer (channel));
        auto* outBuffer = buffer.getWritePointer (channel);
        
        double inGainScaled = pow(10, *inGain * 0.05);
        double outGainScaled = pow(10, *outGain * 0.05);
        
        outGainScaled = pow(10, *outGain * 0.05);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            double input {inBuffer[sample]};
            double saturationScaled = pow(10, (*saturation * .025));
            
            if (*autoParam == 0){
            outBuffer[sample] = (applySaturation(applyGain(input, inGainScaled), saturationScaled, *forceParam) * applyPhase(*rawPhase)) * outGainScaled;
            } else {
                outBuffer[sample] = (applySaturation(applyGain(input, inGainScaled), saturationScaled, *forceParam) * applyPhase(*rawPhase)) * outGainScaled * pow(10, ((*saturation * -.5) * .05));
            }
        }
        
    }
}

//==============================================================================

double ViatorConsoleAudioProcessor::applySaturation(double signal, double drive, int force){
    //force multiples the drive by 4
    if (force == 0){
        return piDivisor * atan(signal * drive) * 1.9;
    } else {
        return piDivisor * atan(signal * (drive * 4)) * .475;
    }
}

//Bunch of filters in series to increase dB per octave
void ViatorConsoleAudioProcessor::updateLowPassFilter(float freq){
    *lowPassFilter.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, freq);
}

void ViatorConsoleAudioProcessor::updateLowPassFilter2(float freq){
    *lowPassFilter2.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, freq);
}

void ViatorConsoleAudioProcessor::updateLowPassFilter3(float freq){
    *lowPassFilter3.state = *dsp::IIR::Coefficients<float>::makeLowPass(lastSampleRate, freq);
}

void ViatorConsoleAudioProcessor::updateHighPassFilter(float freq){
    *highPassFilter.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, freq);
}

void ViatorConsoleAudioProcessor::updateHighPassFilter2(float freq){
    *highPassFilter2.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, freq);
}

void ViatorConsoleAudioProcessor::updateHighPassFilter3(float freq){
    *highPassFilter3.state = *dsp::IIR::Coefficients<float>::makeHighPass(lastSampleRate, freq);
}

double ViatorConsoleAudioProcessor::applyGain(double &input, double &gain){
    return input * gain;
}

int ViatorConsoleAudioProcessor::applyPhase(int p){
    return (-1 -1) * ((p - 0) / (1 - 0)) + 1; //scaling function
}

bool ViatorConsoleAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ViatorConsoleAudioProcessor::createEditor()
{
    return new ViatorConsoleAudioProcessorEditor (*this);
}

//==============================================================================
void ViatorConsoleAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    MemoryOutputStream stream(destData, false);
    treeState.state.writeToStream (stream);
}

void ViatorConsoleAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
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
    return new ViatorConsoleAudioProcessor();
}
