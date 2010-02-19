#include "rectangleoutput.h"
#include "inputobserver.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
RectangleOutput::RectangleOutput(Node* pNode)
: InputObserver(pNode)
{
	color = getColorAttribute(pNode, "color", ofColor());
	position = get2DCoordAttribute(pNode, "position", ofPoint(0,0));
	size = get2DCoordAttribute(pNode, "size", ofPoint(100, 100));
}
//--------------------------------------------------------------
RectangleOutput::RectangleOutput()
{
}
//--------------------------------------------------------------
RectangleOutput::~RectangleOutput()
{
}
//--------------------------------------------------------------
void RectangleOutput::draw()
{
	if(isActive())
	{
		ofSetColor(color.r, color.g, color.b);
		ofRect(position.x, position.y, size.x, size.y);
	}
}
//--------------------------------------------------------------
void RectangleOutput::triggerInternal(InputEvent& event)
{
}
//--------------------------------------------------------------
Output* RectangleOutput::create(Node* pNode)
{
	return new RectangleOutput(pNode);
}