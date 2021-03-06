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

	/*
	 * Create a FftEvent with given eventId, buffersize and fft buffer
	 * The pointer to the buffer is stored in this event
	 * and this class does not own the pointer
	 * (this, to increase performance)
	 */
	FftEvent(int eventId, int buffersize, float* fft);

	/*
	 * When the copy constructor (or assignment) is used, the whole buffer
	 * is copied to a new buffer.
	 */
	FftEvent(const FftEvent& other);

	virtual ~FftEvent();

	/*
	 * When the assignment operator is used, the whole buffer
	 * is copied to a new buffer.
	 */
	FftEvent& operator=(const FftEvent& other);	
	
	/*
	 * Get the size of the buffer
	 */
	int getBufferSize();

	/*
	 * Get a pointer to the buffer
	 */
	float* getFftBuffer();

private:
	void Copy(const FftEvent& other);

	int buffersize;
	float* fft;
	bool bBufferOwner;
};

#endif
