/*
 * InputObserver implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "inputobserver.h"
#include "inputmanager.h"
#include "parseutils.h"
#include "ofMain.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
InputObserver::InputObserver()
{
}
//--------------------------------------------------------------
InputObserver::InputObserver(Node *pNode)
{
	string inputName = getStringAttribute(pNode, "input", "");
	if(!equalsIgnoreCase(inputName, ""))
	{
		InputManager::the().registerObserver(inputName, this);
	}
}
//--------------------------------------------------------------
InputObserver::~InputObserver()
{
}