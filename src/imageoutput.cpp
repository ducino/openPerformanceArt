/*
 * ImageOutput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "imageoutput.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
ImageOutput::ImageOutput(Node* pNode)
: blend(0), bBlend(false)
{
	string filename = getStringAttribute(pNode, "file", "");
	if(equalsIgnoreCase(filename, ""))
	{
		cerr << "No image file specified" << endl;
	}
	else
	{
		//Get the absolute path of the filename (relative to the xml file in which is was defined)
		im.loadImage(getAbsolutePath(pNode, filename));
		position = get2DCoordAttribute(pNode, "position", ofPoint(0,0));
		size = get2DCoordAttribute(pNode, "size", ofPoint(100, 100));
		
		string sBlend = getStringAttribute(pNode, "blend", "");
		if(equalsIgnoreCase(sBlend, ""))
		{
			bBlend = false;
		}
		else
		{
			bBlend = true;
			if(equalsIgnoreCase(sBlend, "add"))
			{
				blend = BLEND_ADD;
			}

		}
	}
}
//--------------------------------------------------------------
ImageOutput::ImageOutput()
{
}
//--------------------------------------------------------------
ImageOutput::~ImageOutput()
{
}
//--------------------------------------------------------------
void ImageOutput::draw()
{
	ofSetColor(0xFFFFFF);
	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT);
	
	if(bBlend)
	{
		if(blend == BLEND_ADD)
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ONE);
		}
	}

	im.draw(position.x, position.y, size.x, size.y);

	glPopAttrib();
}
//--------------------------------------------------------------
Output* ImageOutput::create(Node* pNode)
{
	return new ImageOutput(pNode);
}