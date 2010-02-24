/*
 * EllipseOutput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _ELLIPSE_OUTPUT_H
#define _ELLIPSE_OUTPUT_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "ofMain.h"

class EllipseOutput: public Output
{

public:
	EllipseOutput();
	EllipseOutput(Poco::XML::Node* pNode);
	virtual ~EllipseOutput();

	virtual void draw();
	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofColor color;
	ofPoint position;
	ofPoint size;
};

#endif