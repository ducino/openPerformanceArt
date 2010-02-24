/*
 * AudioInput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "audioinput.h"
#include "parseutils.h"
#include "inputevent.h"
#include "ofxFft.h"

#include "ofMain.h"
#include "Poco/DOM/Node.h"
#include "mainApp.h"

using Poco::XML::Node;
using Poco::Mutex;

//--------------------------------------------------------------
AudioInput::AudioInput()
: bufferSize(512),
  audioInput(NULL),
  fftOutput(NULL),
  fft(NULL)
{
}
//--------------------------------------------------------------
AudioInput::AudioInput(Node* pNode)
: Input(pNode),
  bufferSize(512),
  audioInput(NULL),
  fftOutput(NULL),
  fft(NULL)
{
	//fft = ofxFft::create(bufferSize, OF_FFT_WINDOW_BARTLETT);
	// To use with FFTW, try:
	fft = ofxFft::create(bufferSize, OF_FFT_WINDOW_BARTLETT, OF_FFT_FFTW);

	audioInput = new float[bufferSize];
	fftOutput = new float[fft->getBinSize()];

	static_cast<mainApp*>(ofGetAppPtr())->registerAudioInput(this);
}
//--------------------------------------------------------------
AudioInput::~AudioInput()
{
	delete fft;
	delete audioInput;
	delete fftOutput;
}
//--------------------------------------------------------------
void AudioInput::read()
{
	bufferMutex.lock();

	//Beat detection
	//Calculate total
	total = 0;
	for(int i = 0; i < 5/*fft->getBinSize()*/; i++)
	{
		total += fftOutput[i];
	}

	if(total > threshold*0.7)
	{
		notifyObservers(InputEvent());
	}

	if(total > threshold)
	{
		threshold = total;
		previousThresholdAdjustTime = ofGetElapsedTimeMillis();
	}

	if(ofGetElapsedTimeMillis() - previousThresholdAdjustTime > 1000)
	{
		threshold = threshold*0.95;
		previousThresholdAdjustTime = ofGetElapsedTimeMillis();
	}
	bufferMutex.unlock();
}
//--------------------------------------------------------------
Input* AudioInput::create(Node* pNode)
{
	return new AudioInput(pNode);
}
//--------------------------------------------------------------
int AudioInput::getBufferSize()
{
	return bufferSize;
}
//--------------------------------------------------------------
void AudioInput::audioReceived(float* input, int bufferSize, int nChannels)
{
	bufferMutex.lock();

	// store input in audioInput buffer
	memcpy(audioInput, input, sizeof(float) * bufferSize);

	fft->setSignal(audioInput);
	memcpy(fftOutput, fft->getAmplitude(), sizeof(float) * fft->getBinSize());

	bufferMutex.unlock();
}