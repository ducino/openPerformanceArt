#ifndef _RECTANGLE_OUTPUT_H
#define _RECTANGLE_OUTPUT_H

//Includes
#include "output.h"
#include "inputobserver.h"
#include "ofMain.h"

class RectangleOutput: public Output
{

public:
	RectangleOutput();
	RectangleOutput(Poco::XML::Node* pNode);
	~RectangleOutput();

	virtual void draw();
	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofColor color;
	ofPoint position;
	ofPoint size;
};

#endif