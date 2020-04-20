/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DeJongDistortionAudioProcessorEditor::DeJongDistortionAudioProcessorEditor (DeJongDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    int m_Top_Margin {48};
    int m_Left_Margin {100};
    int m_Text_Box_Width {60};
    int m_Text_Box_Height {32};
    
    m_Sliders_Vector.push_back(&m_In_Gain_Slider);
    m_Sliders_Vector.push_back(&m_A_Slider);
    m_Sliders_Vector.push_back(&m_B_Slider);
    m_Sliders_Vector.push_back(&m_C_Slider);
    m_Sliders_Vector.push_back(&m_D_Slider);
    m_Sliders_Vector.push_back(&m_Out_Gain_Slider);
    
    m_Groups_Vector.push_back(&m_Input_Group);
    m_Groups_Vector.push_back(&m_Left_De_Jong_Group);
    m_Groups_Vector.push_back(&m_Right_De_Jong_Group);
    m_Groups_Vector.push_back(&m_Output_Group);
    
    m_Color_Sliders_Vector.push_back(&m_R_Color_Slider);
    m_Color_Sliders_Vector.push_back(&m_G_Color_Slider);
    m_Color_Sliders_Vector.push_back(&m_B_Color_Slider);
    m_Color_Sliders_Vector.push_back(&m_A_Color_Slider);
    
    //Sliders
    //First Slider's Position
    for (auto i {0}; i < m_Sliders_Vector.size(); i++) {
        
        if (m_Sliders_Vector[i] == &m_In_Gain_Slider){
            m_In_Gain_Slider_Attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, In_Slider_Id, m_In_Gain_Slider);
        } else if (m_Sliders_Vector[i] == &m_A_Slider){
            m_A_Slider_Attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, A_Slider_Id, m_A_Slider);
        } else if (m_Sliders_Vector[i] == &m_B_Slider){
            m_B_Slider_Attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, B_Slider_Id, m_B_Slider);
        } else if (m_Sliders_Vector[i] == &m_C_Slider){
            m_C_Slider_Attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, C_Slider_Id, m_C_Slider);
        } else if (m_Sliders_Vector[i] == &m_D_Slider){
            m_D_Slider_Attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, D_Slider_Id, m_D_Slider);
        } else {
            m_Out_Gain_Slider_Attachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, Out_Slider_Id, m_Out_Gain_Slider);
        }
        
        addAndMakeVisible(m_Sliders_Vector[i]);
        m_Sliders_Vector[i]->setRange(-48.0f, 48.0f, 0.01f);
        m_Sliders_Vector[i]->setTextBoxStyle(Slider::TextBoxBelow, false, m_Text_Box_Width, m_Text_Box_Height);
        m_Sliders_Vector[i]->setSliderStyle(Slider::SliderStyle::LinearVertical);
        m_Sliders_Vector[i]->addListener(this);
        m_Sliders_Vector[i]->setColour(0x1001700, Colour::fromFloatRGBA(1, 1, 1, .25));
        m_Sliders_Vector[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, .25));
        m_Sliders_Vector[i]->setBounds(m_Left_Margin + (i * 100), m_Top_Margin, m_Text_Box_Width, 300);
    }
    
    //Groups and color slider
    for (auto i = 0; i < m_Groups_Vector.size(); i++) {
        
        addAndMakeVisible(m_Groups_Vector[i]);
        m_Groups_Vector[i]->setColour(0x1005400, Colour::fromFloatRGBA(1, 1, 1, 0.25f));
        m_Groups_Vector[i]->setColour(0x1005410, Colour::fromFloatRGBA(1, 1, 1, 0.25f));
        
        addAndMakeVisible(m_Color_Sliders_Vector[i]);
        m_Color_Sliders_Vector[i]->setRange(0.0f, 1.0f, 0.01f);
        m_Color_Sliders_Vector[i]->setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
        m_Color_Sliders_Vector[i]->addListener(this);
        m_Color_Sliders_Vector[i]->setTextBoxStyle(Slider::TextBoxBelow, false, m_Text_Box_Width, m_Text_Box_Height);
        m_Color_Sliders_Vector[i]->setColour(0x1001700, Colour::fromFloatRGBA(1, 1, 1, .25));
        m_Color_Sliders_Vector[i]->setColour(0x1001400, Colour::fromFloatRGBA(1, 1, 1, .25));
        
        //First slider
        if(m_Color_Sliders_Vector[i] == &m_R_Color_Slider){
            
            m_Color_Sliders_Vector[i]->setBounds(m_In_Gain_Slider.getX(), m_In_Gain_Slider.getY() + m_In_Gain_Slider.getHeight() + 48, 128, 128);
            
        } else {
            
            m_Color_Sliders_Vector[i]->setBounds(m_Color_Sliders_Vector[i -1]->getX() + 128, m_Color_Sliders_Vector[i -1]->getY(), 128, 128);
        }
        
        if (m_Groups_Vector[i] == &m_Input_Group){
            
            m_Groups_Vector[i]->setBounds(m_Left_Margin - 16, m_Top_Margin - 24, m_Text_Box_Width + 32, 348);
            m_Groups_Vector[i]->setText("In Gain");
            
        } else if (m_Groups_Vector[i] == &m_Left_De_Jong_Group){
            
            m_Groups_Vector[i]->setBounds(m_Groups_Vector[i -1]->getX() + 102, m_Top_Margin - 24, m_Text_Box_Width + 128, 348);
            m_Groups_Vector[i]->setText("Left De Jong");
            
        } else if (m_Groups_Vector[i] == &m_Right_De_Jong_Group){
            
            m_Groups_Vector[i]->setBounds(m_Groups_Vector[i -1]->getX() + 198, m_Top_Margin - 24, m_Text_Box_Width + 128, 348);
            m_Groups_Vector[i]->setText("Right De Jong");
            
        } else {
            
            m_Groups_Vector[i]->setBounds(m_Groups_Vector[i -1]->getX() + 198, m_Top_Margin - 24, m_Text_Box_Width + 32, 348);
            m_Groups_Vector[i]->setText("Out Gain");
            
        }
    }
    
    addAndMakeVisible(m_Link_Button);
    linkAttach = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(processor.treeState, Link_Id, m_Link_Button);
    m_Link_Button.setButtonText("Link Sides");
    m_Link_Button.setClickingTogglesState(true);
    m_Link_Button.addListener(this);
    m_Link_Button.setColour(0x1000102, Colour::fromFloatRGBA(1, 1, 1, .25));
    m_Link_Button.setColour(0x1000100, Colour::fromFloatRGBA(0, 0, 0, 0));
    m_Link_Button.setColour(0x1000101, Colour::fromFloatRGBA(0, 0, 0, 0));
    m_Link_Button.setColour(0x1000103, Colour::fromFloatRGBA(.23, .77, 1, .5));
    m_Link_Button.setBounds(14, 172, 56, 56);
    
    setSize (m_Out_Gain_Slider.getX() + m_Top_Margin + m_Left_Margin, m_R_Color_Slider.getY() + 152);
}

DeJongDistortionAudioProcessorEditor::~DeJongDistortionAudioProcessorEditor()
{
    m_Sliders_Vector.clear();
    m_Color_Sliders_Vector.clear();
    m_Groups_Vector.clear();
    
}

//==============================================================================
void DeJongDistortionAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour::fromFloatRGBA(0.14f, 0.16f, 0.2f, 1.0f));
}

void DeJongDistortionAudioProcessorEditor::resized()
{
}

void DeJongDistortionAudioProcessorEditor::sliderValueChanged(Slider *slider){
    
    if (m_Link_Button.getToggleState()){
        
        if (slider == &m_A_Slider){
            m_C_Slider.setValue(m_A_Slider.getValue());
        } else if (slider == &m_C_Slider){
            m_A_Slider.setValue(m_C_Slider.getValue());
        }
        
        if (slider == &m_B_Slider){
            m_D_Slider.setValue(m_B_Slider.getValue());
        } else if (slider == &m_D_Slider){
            m_B_Slider.setValue(m_D_Slider.getValue());
        }
    }
    
    if (slider == &m_R_Color_Slider || slider == &m_G_Color_Slider || slider == &m_B_Color_Slider|| slider == &m_A_Color_Slider){
        setRGBA(m_R_Color_Slider.getValue(), m_G_Color_Slider.getValue(), m_B_Color_Slider.getValue(), m_A_Color_Slider.getValue());
    }
}

void DeJongDistortionAudioProcessorEditor::buttonClicked(Button *button){
    
}

void DeJongDistortionAudioProcessorEditor::setRGBA(double red, double green, double blue, double alpha){
    
    for (auto i = 0; i < m_Groups_Vector.size(); i++){
        m_Groups_Vector[i]->setColour(0x1005400, Colour::fromFloatRGBA(red, green, blue, alpha));
        m_Groups_Vector[i]->setColour(0x1005410, Colour::fromFloatRGBA(red, green, blue, alpha));
        m_Color_Sliders_Vector[i]->setColour(0x1001700, Colour::fromFloatRGBA(red, green, blue, alpha));
        m_Color_Sliders_Vector[i]->setColour(0x1001400, Colour::fromFloatRGBA(red, green, blue, alpha));
    }
    
    m_Link_Button.setColour(0x1000102, Colour::fromFloatRGBA(red, blue, green, alpha));
    
    for(auto i = 0; i < m_Sliders_Vector.size(); i++){
        m_Sliders_Vector[i]->setColour(0x1001700, Colour::fromFloatRGBA(red, green, blue, alpha));
        m_Sliders_Vector[i]->setColour(0x1001400, Colour::fromFloatRGBA(red, green, blue, alpha));
    }
    
}

