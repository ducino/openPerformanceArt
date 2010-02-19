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
	activationTime = ofGetElapsedTimeMillis() + interval;
}
//--------------------------------------------------------------
void TimerInput::read()
{
	if(ofGetElapsedTimeMillis() > activationTime)
	{
		updateActivationTime();
		notifyObservers(InputEvent());
	}
}
//--------------------------------------------------------------
Input* TimerInput::create(Node* pNode)
{
	return new TimerInput(pNode);
}