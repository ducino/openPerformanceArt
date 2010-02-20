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
	if(equalsIgnoreCase(inputName, ""))
	{
		cerr << "Warning: The input was not specified for node " << pNode->localName() << endl;
	}
	else
	{
		InputManager::the().registerObserver(inputName, this);
	}
}
//--------------------------------------------------------------
InputObserver::~InputObserver()
{
}