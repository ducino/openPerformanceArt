/*
 * TimerInput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "timerinput.h"
#include "parseutils.h"
#include "inputevent.h"

#include "ofMain.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
TimerInput::TimerInput()
: interval(1000),
  activationTime(0)
{
}
//--------------------------------------------------------------
TimerInput::TimerInput(Node* pNode)
: Input(pNode),
  activationTime(0)
{
	interval = getIntAttribute(pNode, "interval", 1000); 
}
//--------------------------------------------------------------
TimerInput::~TimerInput()
{
}
//--------------------------------------------------------------
void TimerInput::updateActivationTime()
{
	activationTime += interval;
}
//--------------------------------------------------------------
void TimerInput::read()
{
	if(ofGetElapsedTimeMillis() > activationTime)
	{
		updateActivationTime();
		InputEvent event = InputEvent();
		notifyObservers(&event);
	}
}
//--------------------------------------------------------------
Input* TimerInput::create(Node* pNode)
{
	return new TimerInput(pNode);
}