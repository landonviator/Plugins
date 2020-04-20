/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DeJongDistortionAudioProcessor::DeJongDistortionAudioProcessor()
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

DeJongDistortionAudioProcessor::~DeJongDistortionAudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout DeJongDistortionAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<RangedAudioParameter>> params;
    
    auto inParam = std::make_unique<AudioParameterFloat>(In_Slider_Id, In_Slider_Name, -48.0f, 48.0f, 0.0f);
    auto aParam = std::make_unique<AudioParameterFloat>(A_Slider_Id, A_Slider_Name, -48.0f, 48.0f, 0.0f);
    auto bParam = std::make_unique<AudioParameterFloat>(B_Slider_Id, B_Slider_Id, -48.0f, 48.0f, 0.0f);
    auto cParam = std::make_unique<AudioParameterFloat>(C_Slider_Id, C_Slider_Id, -48.0f, 48.0f, 0.0f);
    auto dParam = std::make_unique<AudioParameterFloat>(D_Slider_Id, D_Slider_Id, -48.0f, 48.0f, 0.0f);
    auto outParam = std::make_unique<AudioParameterFloat>(Out_Slider_Id, Out_Slider_Name, -48.0f, 48.0f, 0.0f);
    auto linkParam = std::make_unique<AudioParameterBool>(Link_Id, Link_Name, false);
    
    
    params.push_back(std::move(inParam));
    params.push_back(std::move(aParam));
    params.push_back(std::move(bParam));
    params.push_back(std::move(cParam));
    params.push_back(std::move(dParam));
    params.push_back(std::move(outParam));
    params.push_back(std::move(linkParam));
    
    return { params.begin(), params.end() };
}

//==============================================================================
const String DeJongDistortionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DeJongDistortionAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DeJongDistortionAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DeJongDistortionAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DeJongDistortionAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DeJongDistortionAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DeJongDistortionAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DeJongDistortionAudioProcessor::setCurrentProgram (int index)
{
}

const String DeJongDistortionAudioProcessor::getProgramName (int index)
{
    return {};
}

void DeJongDistortionAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DeJongDistortionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void DeJongDistortionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DeJongDistortionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void DeJongDistortionAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    auto* rawInGain = treeState.getRawParameterValue(In_Slider_Id);
    auto* rawAGain = treeState.getRawParameterValue(A_Slider_Id);
    auto* rawBGain = treeState.getRawParameterValue(B_Slider_Id);
    auto* rawCGain = treeState.getRawParameterValue(C_Slider_Id);
    auto* rawDGain = treeState.getRawParameterValue(D_Slider_Id);
    auto* rawOutGain = treeState.getRawParameterValue(Out_Slider_Id);
    
    auto inParam = pow(10, *rawInGain * .05);
    auto aParam = pow(10, *rawAGain * .05);
    auto bParam = pow(10, *rawBGain * .05);
    auto cParam = pow(10, *rawCGain * .05);
    auto dParam = pow(10, *rawDGain * .05);
    auto outParam = pow(10, *rawOutGain * .05);
    
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* leftOutputBuffer = buffer.getWritePointer (0);
        auto* rightOutputBuffer = buffer.getWritePointer (1);
        auto* leftInputBuffer = buffer.getReadPointer (0);
        auto* rightInputBuffer = buffer.getReadPointer (1);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample){
            
            auto inputSignalLeft = leftInputBuffer[sample] * inParam;
            auto inputSignalRight = rightInputBuffer[sample] * inParam;
            
            double deJongLeft = (sin(inputSignalLeft * aParam) - cos(inputSignalRight * bParam)) * outParam;
            double deJongRight = (sin(inputSignalRight * cParam) - cos(inputSignalLeft * dParam)) * outParam;
            
            leftOutputBuffer[sample] = atan(deJongLeft);
            rightOutputBuffer[sample] = atan(deJongRight);
            
            inputSignalLeft = deJongLeft;
            inputSignalRight = deJongRight;
            
        }
    }
}

//==============================================================================
bool DeJongDistortionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DeJongDistortionAudioProcessor::createEditor()
{
    return new DeJongDistortionAudioProcessorEditor (*this);
}

//==============================================================================
void DeJongDistortionAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DeJongDistortionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DeJongDistortionAudioProcessor();
}
