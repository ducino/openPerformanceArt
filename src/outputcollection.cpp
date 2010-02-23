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
	//Clean up the outputs
	{
		vector<Output*>::iterator iter;
		for( iter = outputs.begin(); iter != outputs.end(); ++iter ) {
			delete (*iter);
		}
		outputs.clear();
	}
}
//--------------------------------------------------------------
void OutputCollection::drawAllOutputs()
{
	//Draw all outputs
	vector<Output*>::iterator iter;
	for( iter = outputs.begin(); iter != outputs.end(); ++iter ) {
		(*iter)->draw();
	}
}