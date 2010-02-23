/*
 * InputEvent class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _INPUT_EVENT_H
#define _INPUT_EVENT_H

class InputEvent
{
public:
	InputEvent();
	InputEvent(int eventId);
	~InputEvent();

	/*
	 * Get the event identifier
	 */
	int getEventId();

private:
	int eventId;
};

#endif
