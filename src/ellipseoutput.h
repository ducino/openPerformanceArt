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
	~EllipseOutput();

	virtual void draw();
	virtual Output* create(Poco::XML::Node* pNode);

private:
	ofColor color;
	ofPoint position;
	ofPoint size;
};

#endif