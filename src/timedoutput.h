/*
 * TimedOutput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _TIMED_OUTPUT_H
#define _TIMED_OUTPUT_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "outputcollection.h"
#include "ofMain.h"

class TimedOutput: public OutputCollection
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
};

#endif