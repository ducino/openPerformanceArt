/*
 * InputEvent implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
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
int InputEvent::getEventId() const
{
	return eventId;
}