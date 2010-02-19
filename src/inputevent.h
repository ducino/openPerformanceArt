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
