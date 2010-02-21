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