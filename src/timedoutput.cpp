#include "timedoutput.h"
#include "inputobserver.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
TimedOutput::TimedOutput(Node* pNode)
: OutputCollection(pNode)
{
	duration = getIntAttribute(pNode, "duration", 0);
}
//--------------------------------------------------------------
TimedOutput::TimedOutput()
{
}
//--------------------------------------------------------------
TimedOutput::~TimedOutput()
{
}
//--------------------------------------------------------------
void TimedOutput::draw()
{
	if(isActive())
	{
		drawAllOutputs();
	}
}
//--------------------------------------------------------------
void TimedOutput::trigger(InputEvent& event)
{
	previousTriggerTime = ofGetElapsedTimeMillis();
}
//--------------------------------------------------------------
Output* TimedOutput::create(Node* pNode)
{
	return new TimedOutput(pNode);
}
//--------------------------------------------------------------
bool TimedOutput::isActive()
{
	return duration == 0 || (ofGetElapsedTimeMillis() - previousTriggerTime < duration);
}