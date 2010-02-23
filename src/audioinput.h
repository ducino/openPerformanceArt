/*
 * AudioInput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _AUDIO_INPUT_H
#define _AUDIO_INPUT_H

//Includes
#include "input.h"

//Forward declarations
class ofxFft;
namespace Poco { namespace XML { class Node; }}

class AudioInput: public Input 
{

public:
	AudioInput();
	AudioInput(Poco::XML::Node* pNode);
	~AudioInput();

	virtual void read();

	virtual Input* create(Poco::XML::Node* pNode);

	int getBufferSize();

	void audioReceived(float* input, int bufferSize, int nChannels);

private:
	ofxFft* fft;
	int bufferSize;
	float* audioInput;
	float* fftOutput;

	//Beat detection
	float total;
	float threshold;
	long previousThresholdAdjustTime;
};

#endif
