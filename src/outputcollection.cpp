#include "outputcollection.h"
#include "scenefactory.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
OutputCollection::OutputCollection(Node* pNode)
: InputObserver(pNode)
{
	SceneFactory::the().loadOutputs(outputs, pNode);
}
//--------------------------------------------------------------
OutputCollection::OutputCollection()
{
}
//--------------------------------------------------------------
OutputCollection::~OutputCollection()
{
}
//--------------------------------------------------------------