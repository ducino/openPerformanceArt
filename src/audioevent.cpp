/*
 * AudioEvent implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "audioevent.h"
#include <iostream>

//--------------------------------------------------------------
AudioEvent::AudioEvent()
:InputEvent(0),
 audioBuffer(NULL),
 bBufferOwner(false)
{
}
//--------------------------------------------------------------
AudioEvent::AudioEvent(int eventId, int buffersize, float* buffer)
: InputEvent(eventId),
  bBufferOwner(false)
{
	audioBuffer = buffer;
	this->buffersize = buffersize;
}
//--------------------------------------------------------------
AudioEvent::AudioEvent(const AudioEvent& other)
{
	Copy(other);
}
//--------------------------------------------------------------
AudioEvent& AudioEvent::operator=(const AudioEvent& other)
{
	Copy(other);
	return *this;
}
//--------------------------------------------------------------
void AudioEvent::Copy(const AudioEvent& other)
{
	InputEvent::Copy(other);
	audioBuffer = new float[other.buffersize];
	buffersize = other.buffersize;
	memcpy(audioBuffer, other.audioBuffer, sizeof(float) * buffersize);
	bBufferOwner = true;
}
//--------------------------------------------------------------
AudioEvent::~AudioEvent()
{
	if(bBufferOwner)
	{
		delete [] audioBuffer;
	}
}
//--------------------------------------------------------------
int AudioEvent::getBufferSize()
{
	return buffersize;
}
//--------------------------------------------------------------
float* AudioEvent::getAudioBuffer()
{
	return audioBuffer;
}
