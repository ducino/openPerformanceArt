/*
 * RandomPick class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _RANDOM_PICK_H
#define _RANDOM_PICK_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "outputcollection.h"
#include "ofMain.h"

class RandomPick: public OutputCollection
{

public:
	RandomPick();
	RandomPick(Poco::XML::Node* pNode);
	~RandomPick();

	virtual void draw();
	virtual void trigger(InputEvent& event);
	virtual Output* create(Poco::XML::Node* pNode);
};

#endif