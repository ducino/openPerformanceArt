/*
 * RandomPick implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "randompick.h"
#include "inputobserver.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
RandomPick::RandomPick(Node* pNode)
: OutputCollection(pNode)
{
}
//--------------------------------------------------------------
RandomPick::RandomPick()
{
}
//--------------------------------------------------------------
RandomPick::~RandomPick()
{
}
//--------------------------------------------------------------
void RandomPick::draw()
{
	drawAllOutputs();
}
//--------------------------------------------------------------
void RandomPick::trigger(InputEvent* event)
{
	int pick = ofRandom(0, outputs.size());
	InputObserver* observer = static_cast<InputObserver*>(outputs[pick]);
	observer->trigger(event);
}
//--------------------------------------------------------------
Output* RandomPick::create(Node* pNode)
{
	return new RandomPick(pNode);
}