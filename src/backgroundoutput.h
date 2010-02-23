/*
 * BackgroundOutput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _BACKGROUND_OUTPUT_H
#define _BACKGROUND_OUTPUT_H

//Includes
#include "output.h"
#include "ofMain.h"

class BackgroundOutput: public Output 
{

public:
	BackgroundOutput();
	BackgroundOutput(Poco::XML::Node* pNode);
	~BackgroundOutput();

	virtual void draw();

	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofColor color;
};

#endif