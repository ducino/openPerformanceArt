#include "audioinput.h"
#include "parseutils.h"
#include "inputevent.h"
#include "ofxFft.h"

#include "ofMain.h"
#include "Poco/DOM/Node.h"
#include "mainApp.h"

using Poco::XML::Node;

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
	// store input in audioInput buffer
	memcpy(audioInput, input, sizeof(float) * bufferSize);

	fft->setSignal(audioInput);
	memcpy(fftOutput, fft->getAmplitude(), sizeof(float) * fft->getBinSize());

	//Beat detection
	//Calculate total
	total = 0;
	for(int i = 0; i < 10/*fft->getBinSize()*/; i++)
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
}