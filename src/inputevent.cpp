#include "inputevent.h"

//--------------------------------------------------------------
InputEvent::InputEvent()
:eventId(0)
{
}
//--------------------------------------------------------------
InputEvent::InputEvent(int eventId)
:eventId(eventId)
{
}
//--------------------------------------------------------------
InputEvent::~InputEvent()
{
}
//--------------------------------------------------------------
int InputEvent::getEventId()
{
	return eventId;
}