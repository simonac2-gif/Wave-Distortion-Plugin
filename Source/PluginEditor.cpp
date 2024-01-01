/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionVSTAudioProcessorEditor::DistortionVSTAudioProcessorEditor (DistortionVSTAudioProcessor& p)
    : AudioProcessorEditor (&p), audioVisualizer(2), audioProcessor (p)
{
	mix_slider.setSliderStyle(juce::Slider::Rotary);
	mix_slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 42);
	mix_slider.setRange(0, 100, 1);
	addAndMakeVisible(mix_slider);
	mix_slider.setDoubleClickReturnValue(true, 0);

	addAndMakeVisible(mix_label);
	mix_label.setText("Tone", juce::dontSendNotification);
	mix_label.attachToComponent(&mix_slider, false);

	dynamics_slider.setSliderStyle(juce::Slider::Rotary);
	dynamics_slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 42);
	dynamics_slider.setRange(0, 100, 1);
	addAndMakeVisible(dynamics_slider);
	dynamics_slider.setDoubleClickReturnValue(true, 0);

	addAndMakeVisible(dynamics_label);
	dynamics_label.setText("Volume", juce::dontSendNotification);
	dynamics_label.attachToComponent(&dynamics_slider, false);
	
	drive_slider.setSliderStyle(juce::Slider::Rotary);
	drive_slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 42);
	drive_slider.setRange(0, 100, 1);
	addAndMakeVisible(drive_slider);
	drive_slider.setDoubleClickReturnValue(true, 0);

	addAndMakeVisible(drive_label);
	drive_label.setText("Distortion", juce::dontSendNotification);
	drive_label.attachToComponent(&drive_slider, false);


	//addAndMakeVisible(drive_menu);
	//drive_menu.addItem("First", 1);
	//drive_menu.addItem("Second", 2);
	//drive_menu.addItem("Third", 3);

	//hibutton.setClickingTogglesState(true);
	//hibutton.onClick = [&]() {
	//	const auto msg = hibutton.getToggleState() ? "Hi!" : "Hello";
	//	printf(msg);
	//	hibutton.setButtonText(msg);
	//};

	addAndMakeVisible(inputbutton);
	inputbutton.onClick = [this] { inputButtonClicked(); };

	addAndMakeVisible(audioVisualizer);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

	// allow resizing
	setResizable(true, true);
	setSize(500, 300);
}

DistortionVSTAudioProcessorEditor::~DistortionVSTAudioProcessorEditor()
{
}

//==============================================================================
void DistortionVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    //g.setColour (juce::Colours::white);
    //g.setFont (15.0f);
    //g.drawFittedText ("Distortion VST plugin!", getLocalBounds(), juce::Justification::centred, 1);
}

void DistortionVSTAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	auto border = 10;

	auto area = getLocalBounds();

	// hibutton.setBounds(border, border, 100, 50);

	auto sliderArea = area.removeFromTop(area.getHeight() / 10);
	sliderArea = area.removeFromTop(area.getHeight() / 2);
	auto slider_width = sliderArea.getWidth() / 3;
	mix_slider.setBounds(sliderArea.removeFromLeft(slider_width).reduced(border));
	dynamics_slider.setBounds(sliderArea.removeFromLeft(slider_width).reduced(border));
	drive_slider.setBounds(sliderArea.removeFromLeft(slider_width).reduced(border));

	auto buttonHeight = 20;
	auto buttonarea = area.removeFromTop(buttonHeight);
	buttonarea.removeFromLeft(buttonHeight);
	buttonarea.removeFromRight(buttonHeight);
	inputbutton.setBounds(buttonarea);

	auto wave_screen = area;
	audioVisualizer.setBounds(wave_screen);

	// drive_menu.setBounds(area.removeFromBottom(buttonHeight*2));
	// drive_menu.setBounds(sliderArea.removeFromTop(buttonHeight).reduced(border), 50, 50, 50);
	// hibutton.setBounds(sliderArea.removeFromTop(buttonHeight).reduced(border), 50, 50, 50);
}
