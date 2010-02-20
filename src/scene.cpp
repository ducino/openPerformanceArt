#include "scene.h"
#include "inputmanager.h"
#include "output.h"
#include "scenefactory.h"
#include "Poco/DOM/Node.h"
#include "Poco/DOM/Document.h"
#include "parseutils.h"

using Poco::XML::Node;

//--------------------------------------------------------------
Scene::Scene(Node* pNode)
{
	SceneFactory::the().loadOutputs(outputs, pNode);
}
//--------------------------------------------------------------
Scene::~Scene()
{
	//Clean up the outputs
	{
		vector<Output*>::iterator iter;
		for( iter = outputs.begin(); iter != outputs.end(); ++iter ) {
			delete *iter;
		}
		outputs.clear();
	}
}
//--------------------------------------------------------------
void Scene::update()
{
	//Read all inputs
	InputManager::the().read();
}
//--------------------------------------------------------------
void Scene::draw()
{
	//Draw all outputs
	vector<Output*>::iterator iter;
	for( iter = outputs.begin(); iter != outputs.end(); ++iter ) {
		(*iter)->draw();
	}
}
//--------------------------------------------------------------
void Scene::add(Output* output)
{
	outputs.push_back(output);
}