/*
 * AudioInput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "audioinput.h"
#include "parseutils.h"
#include "inputevent.h"
#include "fftevent.h"
#include "audioevent.h"
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
  fft(NULL),
  bAudioReceived(false)
{
}
//--------------------------------------------------------------
AudioInput::AudioInput(Node* pNode)
: Input(pNode),
  bufferSize(512),
  audioInput(NULL),
  fftOutput(NULL),
  fft(NULL),
  bAudioReceived(false)
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

	if(bAudioReceived)
	{
		//Send fft event
		FftEvent fftEvent(0, fft->getBinSize(), fftOutput);
		notifyObservers(&fftEvent);

		//Send audio event
		AudioEvent audioEvent(1, bufferSize, audioInput);
		notifyObservers(&audioEvent);

		bAudioReceived = false;
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
	
	bAudioReceived = true;

	// store input in audioInput buffer
	memcpy(audioInput, input, sizeof(float) * bufferSize);

	fft->setSignal(audioInput);
	memcpy(fftOutput, fft->getAmplitude(), sizeof(float) * fft->getBinSize());

	bufferMutex.unlock();
}