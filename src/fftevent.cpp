/*
 * FftEvent implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "fftevent.h"
#include <iostream>

//--------------------------------------------------------------
FftEvent::FftEvent()
:InputEvent(0),
 fft(NULL),
 bBufferOwner(false)
{
}
//--------------------------------------------------------------
FftEvent::FftEvent(int eventId, int buffersize, float* fft)
: InputEvent(eventId),
  bBufferOwner(false)
{
	this->fft = fft;
	this->buffersize = buffersize;
}
//--------------------------------------------------------------
FftEvent::FftEvent(const FftEvent& other)
{
	Copy(other);
}
//--------------------------------------------------------------
FftEvent& FftEvent::operator=(const FftEvent& other)
{
	Copy(other);
	return *this;
}
//--------------------------------------------------------------
void FftEvent::Copy(const FftEvent& other)
{
	InputEvent::Copy(other);
	fft = new float[other.buffersize];
	buffersize = other.buffersize;
	memcpy(this->fft, other.fft, sizeof(float) * buffersize);
	bBufferOwner = true;
}
//--------------------------------------------------------------
FftEvent::~FftEvent()
{
	if(bBufferOwner)
	{
		delete [] fft;
	}
}
//--------------------------------------------------------------
int FftEvent::getBufferSize()
{
	return buffersize;
}
//--------------------------------------------------------------
float* FftEvent::getFftBuffer()
{
	return fft;
}
