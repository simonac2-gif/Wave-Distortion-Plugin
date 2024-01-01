# JUCE Wave-Distortion effect VST Plugin

## What is it?

The Distortion effect plugin is a waveshaper-based distortion plugin designed to add distortion to provided sound using the JUCE framework. It aims at those who are working in a Digital Audio Workstation and those who are attempting to use the effect online. Key functionalities include:
1. Users can import the VST plugin to their DAW and use the effect on audio in their DAW. 
2. Users can upload their audio files and apply effects to their audio files.
3. Buttons and sliders to adjust and clip tone parameters.
4. A waveform viewer that the user can see on the UI.

# Developers

- **Michael Kazmerski (mk67)** and **Simon Cooper (simonac2)**: signal processing of the distortion plugin
- **Matt Yang (zihuiy3)** and **Rose Zhang (rosez2)**: user interface for the (VST) plugin.

# Environmental setup

## Installation

Users would need to install:
1. [JUCE](https://juce.com/) and uncompress the zip file
2. A C++ development environment that is supported by JUCE, preferably Visual Studio for Windows and XCode for MAC
3. Distortion effect VST Plugin source file

## Usage

1. Open Projucer.exe and click on "File" on the top left corner, click on Open, then select the file named "NewProject_t.jucer". Projucer will then load the source code. 

2. Select the preferred IDE in the dropdown menu and click on the button next to it. This will open the source code in your IDE.

3. Hit Run in your IDE and the Distortion plugin will pop up. 
