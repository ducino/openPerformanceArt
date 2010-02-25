/*
 * BeatDetect class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _BEAT_DETECT_H
#define _BEAT_DETECT_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "outputcollection.h"
#include "ofMain.h"
#include "dynamicthreshold.h"

class BeatDetect: public OutputCollection
{

public:
	BeatDetect();
	BeatDetect(Poco::XML::Node* pNode);
	virtual ~BeatDetect();

	virtual void draw();
	virtual void trigger(InputEvent* event);
	virtual Output* create(Poco::XML::Node* pNode);

private:
	DynamicThreshold* threshold;
};

#endif