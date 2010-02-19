#ifndef _TIMED_OUTPUT_H
#define _TIMED_OUTPUT_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "ofMain.h"

class TimedOutput: public Output, public InputObserver
{

public:
	TimedOutput();
	TimedOutput(Poco::XML::Node* pNode);
	~TimedOutput();

	virtual void draw();
	virtual void trigger(InputEvent& event);
	virtual Output* create(Poco::XML::Node* pNode);

private:
	bool isActive();

	long previousTriggerTime;
	long duration;

	vector<Output*> outputs;
};

#endif