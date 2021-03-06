/*
 * BackgroundOutput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "backgroundoutput.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
BackgroundOutput::BackgroundOutput(Node* pNode)
{
	color = getColorAttribute(pNode, "color", ofColor());
}
//--------------------------------------------------------------
BackgroundOutput::BackgroundOutput()
{
}
//--------------------------------------------------------------
BackgroundOutput::~BackgroundOutput()
{
}
//--------------------------------------------------------------
void BackgroundOutput::draw()
{
	ofBackground(color.r, color.g, color.b);
}
//--------------------------------------------------------------
Output* BackgroundOutput::create(Node* pNode)
{
	return new BackgroundOutput(pNode);
}