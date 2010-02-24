/*
 * VideoOutput class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _VIDEO_OUTPUT_H
#define _VIDEO_OUTPUT_H

//Includes
#include "output.h"
#include "ofTypes.h"

//Foward declarations
class ofVideoPlayer;

#define BLEND_NONE 0
#define BLEND_ADD 1

class VideoOutput: public Output
{

public:
	VideoOutput();
	VideoOutput(Poco::XML::Node* pNode);
	virtual ~VideoOutput();

	virtual void draw();
	virtual void update();
	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofVideoPlayer* video;
	ofPoint position;
	ofPoint size;
	bool	bBlend;
	int		blend;
};

#endif