/*
 * BeatDetect implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "beatdetect.h"
#include "audioevent.h"
#include "inputobserver.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
BeatDetect::BeatDetect(Node* pNode)
: OutputCollection(pNode),
  threshold(NULL)
{
	threshold = new DynamicThreshold(1000, 0.5);
}
//--------------------------------------------------------------
BeatDetect::BeatDetect()
: threshold(NULL)
{
}
//--------------------------------------------------------------
BeatDetect::~BeatDetect()
{
	delete threshold;
}
//--------------------------------------------------------------
void BeatDetect::draw()
{
	drawAllOutputs();
}
//--------------------------------------------------------------
void BeatDetect::trigger(InputEvent* event)
{
	if(event->getEventId() == 1)
	{
		AudioEvent* audioEvent = static_cast<AudioEvent*>(event);

		float totalEnergy = 0;
		float* buffer = audioEvent->getAudioBuffer();
		for(int i = 0; i < audioEvent->getBufferSize(); i++)
		{
			totalEnergy += (buffer[i]*buffer[i]);
		}

		cout << totalEnergy << endl;

		if(threshold->check(totalEnergy))
		{
			cout << "beat" << endl;
			for(int i = 0; i < outputs.size(); i++)
			{
				InputObserver* observer = static_cast<InputObserver*>(outputs[i]);
				observer->trigger(event);
			}
		}
	}
}
//--------------------------------------------------------------
Output* BeatDetect::create(Node* pNode)
{
	return new BeatDetect(pNode);
}