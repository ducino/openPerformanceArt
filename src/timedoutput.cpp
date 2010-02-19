#include "timedoutput.h"
#include "inputobserver.h"
#include "scenefactory.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
TimedOutput::TimedOutput(Node* pNode)
: InputObserver(pNode)
{
	duration = getIntAttribute(pNode, "duration", 0);

	SceneFactory::the().loadOutputs(outputs, pNode);
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
		//Draw all outputs
		vector<Output*>::iterator iter;
		for( iter = outputs.begin(); iter != outputs.end(); ++iter ) {
			(*iter)->draw();
		}
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