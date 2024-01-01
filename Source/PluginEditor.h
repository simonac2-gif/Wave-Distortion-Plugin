/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DistortionVSTAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DistortionVSTAudioProcessorEditor (DistortionVSTAudioProcessor&);
    ~DistortionVSTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DistortionVSTAudioProcessor& audioProcessor;

	juce::TextButton inputbutton{ "Open..." };

	// tone
	juce::Slider mix_slider;
	juce::Label mix_label;
	// volume 
	juce::Slider dynamics_slider;
	juce::Label dynamics_label;
	// distortion
	juce::Slider drive_slider;
	juce::Label drive_label;

	juce::ComboBox drive_menu{ "Hi" };

	juce::AudioVisualiserComponent audioVisualizer;

	enum TransportState
	{
		Stopped,
		Starting,
		Playing,
		Stopping
	};

	std::unique_ptr<juce::FileChooser> chooser;

	juce::AudioFormatManager formatManager;
	std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
	juce::AudioTransportSource transportSource;
	TransportState state;

	void inputButtonClicked()
	{
		chooser = std::make_unique<juce::FileChooser>("Select a Wave file to play...",
			juce::File{},
			"*.wav");                     // [7]
		auto chooserFlags = juce::FileBrowserComponent::openMode
			| juce::FileBrowserComponent::canSelectFiles;

		chooser->launchAsync(chooserFlags, [this](const juce::FileChooser& fc)     // [8]
		{
			auto file = fc.getResult();

			if (file != juce::File{})                                                // [9]
			{
				auto* reader = formatManager.createReaderFor(file);                 // [10]

				if (reader != nullptr)
				{
					auto newSource = std::make_unique<juce::AudioFormatReaderSource>(reader, true);   // [11]
					transportSource.setSource(newSource.get(), 0, nullptr, reader->sampleRate);       // [12]
					// playButton.setEnabled(true);                                                      // [13]
					readerSource.reset(newSource.release());                                          // [14]
				}
			}
		});
	}

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionVSTAudioProcessorEditor)
};