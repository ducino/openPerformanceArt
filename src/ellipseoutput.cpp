/*
 * EllipseOutput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "ellipseoutput.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
EllipseOutput::EllipseOutput(Node* pNode)
{
	color = getColorAttribute(pNode, "color", ofColor());
	position = get2DCoordAttribute(pNode, "position", ofPoint(0,0));
	size = get2DCoordAttribute(pNode, "size", ofPoint(100, 100));
}
//--------------------------------------------------------------
EllipseOutput::EllipseOutput()
{
}
//--------------------------------------------------------------
EllipseOutput::~EllipseOutput()
{
}
//--------------------------------------------------------------
void EllipseOutput::draw()
{
	ofSetColor(color.r, color.g, color.b);	
	ofEllipse(position.x, position.y, size.x, size.y);
}
//--------------------------------------------------------------
Output* EllipseOutput::create(Node* pNode)
{
	return new EllipseOutput(pNode);
}