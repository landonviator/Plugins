/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class DeJongDistortionAudioProcessorEditor  : public AudioProcessorEditor, public Button::Listener, public Slider::Listener
{
public:
    DeJongDistortionAudioProcessorEditor (DeJongDistortionAudioProcessor&);
    ~DeJongDistortionAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider *slider) override;
    void buttonClicked(Button *button) override;
    void setRGBA(double red, double green, double blue, double alpha);
    

private:
    
    Slider m_In_Gain_Slider, m_A_Slider, m_B_Slider, m_C_Slider, m_D_Slider, m_Out_Gain_Slider;
    Slider m_R_Color_Slider, m_G_Color_Slider, m_B_Color_Slider, m_A_Color_Slider;
    GroupComponent m_Input_Group, m_Left_De_Jong_Group, m_Right_De_Jong_Group, m_Output_Group;
    TextButton m_Link_Button;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> m_In_Gain_Slider_Attachment, m_A_Slider_Attachment, m_B_Slider_Attachment, m_C_Slider_Attachment, m_D_Slider_Attachment,
    m_Out_Gain_Slider_Attachment;
    
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> linkAttach;
    
    std::vector<Slider*> m_Sliders_Vector;
    std::vector<Slider*> m_Color_Sliders_Vector;
    std::vector<GroupComponent*> m_Groups_Vector;
    
    DeJongDistortionAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DeJongDistortionAudioProcessorEditor)
};
