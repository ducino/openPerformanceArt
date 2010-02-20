#include "roundrobin.h"
#include "inputobserver.h"
#include "ofMain.h"
#include "parseutils.h"
#include "Poco/DOM/Node.h"

using Poco::XML::Node;

//--------------------------------------------------------------
RoundRobin::RoundRobin(Node* pNode)
: OutputCollection(pNode),
  currentOutput(0)
{
}
//--------------------------------------------------------------
RoundRobin::RoundRobin()
{
}
//--------------------------------------------------------------
RoundRobin::~RoundRobin()
{
}
//--------------------------------------------------------------
void RoundRobin::draw()
{
	//Draw all outputs
	vector<Output*>::iterator iter;
	for( iter = outputs.begin(); iter != outputs.end(); ++iter ) {
		(*iter)->draw();
	}
}
//--------------------------------------------------------------
void RoundRobin::trigger(InputEvent& event)
{
	InputObserver* observer = static_cast<InputObserver*>(outputs[currentOutput]);
	observer->trigger(event);

	currentOutput = (currentOutput+1)%outputs.size();
}
//--------------------------------------------------------------
Output* RoundRobin::create(Node* pNode)
{
	return new RoundRobin(pNode);
}