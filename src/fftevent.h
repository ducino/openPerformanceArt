/*
 * FftEvent class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _FFT_EVENT_H
#define _FFT_EVENT_H

#include "inputevent.h"

class FftEvent : public InputEvent
{
public:
	FftEvent();
	FftEvent(int eventId, int buffersize, float* fft);
	virtual ~FftEvent();
	FftEvent(const FftEvent& other);
	FftEvent& operator=(const FftEvent& other);
	void Copy(const FftEvent& other);
	
	int getBufferSize();
	float* getFftBuffer();

private:
	int buffersize;
	float* fft;
};

#endif
