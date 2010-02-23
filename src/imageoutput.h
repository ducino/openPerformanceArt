/*
 * ImageOutput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _IMAGE_OUTPUT_H
#define _IMAGE_OUTPUT_H

//Includes
#include "output.h"
#include "ofMain.h"

#define BLEND_NONE 0
#define BLEND_ADD 1

class ImageOutput: public Output
{

public:
	ImageOutput();
	ImageOutput(Poco::XML::Node* pNode);
	~ImageOutput();

	virtual void draw();
	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofImage im;
	ofPoint position;
	ofPoint size;
	bool	bBlend;
	int		blend;
};

#endif