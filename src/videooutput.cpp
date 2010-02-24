/*
 * VideoOutput implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "videooutput.h"
#include "videopool.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"
#include "mainApp.h"

using Poco::XML::Node;

//--------------------------------------------------------------
VideoOutput::VideoOutput(Node* pNode)
: blend(0), 
  bBlend(false), 
  video(NULL)
{
	
	string filename = getStringAttribute(pNode, "file", "");
	if(equalsIgnoreCase(filename, ""))
	{
		cerr << "No image file specified" << endl;
	}
	else
	{
		//Acquire a player from the pool
		video = static_cast<mainApp*>(ofGetAppPtr())->getVideoPool().acquire();

		if(video == NULL)
		{
			cerr << "Could not acquire a video player" << endl;
		}
		else
		{
			//Get the absolute path of the filename (relative to the xml file in which is was defined)
			video->loadMovie(getAbsolutePath(pNode, filename));
			video->play();

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
}
//--------------------------------------------------------------
VideoOutput::VideoOutput()
: video(NULL)
{
}
//--------------------------------------------------------------
VideoOutput::~VideoOutput()
{
	try
	{
		//Clean up video resources
		video->closeMovie();
		//Release the video back to the pool
		static_cast<mainApp*>(ofGetAppPtr())->getVideoPool().release(video);
	}
	catch(...)
	{
		//This crashes on exit of application
		//The video is already deallocated before
		//this destructor is called
	}
}
//--------------------------------------------------------------
void VideoOutput::draw()
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

	video->draw(position.x, position.y, size.x, size.y);

	glPopAttrib();
}
//--------------------------------------------------------------
void VideoOutput::update()
{
	video->idleMovie();
}
//--------------------------------------------------------------
Output* VideoOutput::create(Node* pNode)
{
	return new VideoOutput(pNode);
}