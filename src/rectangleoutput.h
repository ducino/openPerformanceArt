/*
 * RectangleOutput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _RECTANGLE_OUTPUT_H
#define _RECTANGLE_OUTPUT_H

//Includes
#include "output.h"
#include "ofMain.h"

class RectangleOutput: public Output
{

public:
	RectangleOutput();
	RectangleOutput(Poco::XML::Node* pNode);
	virtual ~RectangleOutput();

	virtual void draw();
	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofColor color;
	ofPoint position;
	ofPoint size;
};

#endif