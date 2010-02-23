/*
 * Input implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "input.h"
#include "inputobserver.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
Input::Input()
{
}
//--------------------------------------------------------------
Input::Input(Node* pNode)
{
	name = getStringAttribute(pNode, "name", "");
	if(equalsIgnoreCase(name, ""))
	{
		cerr << "The name was not specified for node " << pNode->localName() << endl;
	}
}
//--------------------------------------------------------------
Input::~Input()
{
}
//--------------------------------------------------------------
string Input::getName() const
{
	return name;
}
//--------------------------------------------------------------
void Input::add(InputObserver* observer)
{
	observers.push_back(observer);
}
//--------------------------------------------------------------
void Input::removeAllObservers()
{
	observers.clear();
}
//--------------------------------------------------------------
void Input::notifyObservers(InputEvent event)
{
	for( vector<InputObserver*>::const_iterator iter = observers.begin();
		iter != observers.end(); ++iter ) 
	{
		(*iter)->trigger(event);
	}
}