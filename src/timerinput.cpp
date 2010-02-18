#include "timerinput.h"
#include "parseutils.h"

#include "ofMain.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
TimerInput::TimerInput(Node* pNode)
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

		//TODO activate
	}
}