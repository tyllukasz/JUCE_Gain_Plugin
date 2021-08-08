/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Gain_PluginAudioProcessorEditor::Gain_PluginAudioProcessorEditor (Gain_PluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //SLIDER
    
        //slider style definition
        myGainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);

        //text box style/position
        myGainSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 20);

        //slider range definition
        myGainSlider.setRange(-60.0f, 0.0f, 0.01f);

        //slider initial value
        myGainSlider.setValue(-20.0f);

        //sliderListener
        myGainSlider.addListener(this);

        addAndMakeVisible(myGainSlider);
    
 
    //editor's size
    setSize (200, 300);
}

Gain_PluginAudioProcessorEditor::~Gain_PluginAudioProcessorEditor()
{
}

//==============================================================================
void Gain_PluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    //background colour
    g.fillAll(juce::Colours::crimson);
}

void Gain_PluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    myGainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}


void Gain_PluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
    if (slider == &myGainSlider)
    {
        audioProcessor.myGain = myGainSlider.getValue();
        
    }
}