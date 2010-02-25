/*
 * AudioEvent class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _AUDIO_EVENT_H
#define _AUDIO_EVENT_H

#include "inputevent.h"

class AudioEvent : public InputEvent
{
public:
	AudioEvent();

	/*
	 * Create a AudioEvent with given eventId, buffersize and audio buffer
	 * The pointer to the buffer is stored in this event
	 * and this class does not own the pointer
	 * (this, to increase performance)
	 */
	AudioEvent(int eventId, int buffersize, float* buffer);

	/*
	 * When the copy constructor (or assignment) is used, the whole buffer
	 * is copied to a new buffer.
	 */
	AudioEvent(const AudioEvent& other);

	virtual ~AudioEvent();

	/*
	 * When the assignment operator is used, the whole buffer
	 * is copied to a new buffer.
	 */
	AudioEvent& operator=(const AudioEvent& other);

	/*
	 * Get the size of the buffer
	 */
	int getBufferSize();

	/*
	 * Get a pointer to the buffer
	 */
	float* getAudioBuffer();

private:
	void Copy(const AudioEvent& other);

	int buffersize;
	float* audioBuffer;
	bool bBufferOwner;
};

#endif
