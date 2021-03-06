/*
 * RoundRobin class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _ROUND_ROBIN_H
#define _ROUND_ROBIN_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "outputcollection.h"
#include "ofMain.h"

class RoundRobin: public OutputCollection
{

public:
	RoundRobin();
	RoundRobin(Poco::XML::Node* pNode);
	virtual ~RoundRobin();

	virtual void draw();
	virtual void trigger(InputEvent* event);
	virtual Output* create(Poco::XML::Node* pNode);

private:
	int currentOutput;
};

#endif