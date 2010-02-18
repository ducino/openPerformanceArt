#include "sceneproxy.h"
#include "scene.h"
#include "parseutils.h"

#include "ofMain.h"
#include "Poco/DOM/Node.h"
#include "Poco/DOM/NamedNodeMap.h"

using Poco::XML::Node;
using Poco::XML::NamedNodeMap;

//--------------------------------------------------------------
SceneProxy::SceneProxy(Node* pNode)
: pScene(NULL)
{
	this->pNode = pNode->cloneNode(true);

	//Read name of this scene
	name = getStringAttribute(pNode, "name", "No name");

	pFont = new ofTrueTypeFont();
	pFont->loadFont("AnnabelScript.ttf", 30);
}
//--------------------------------------------------------------
SceneProxy::~SceneProxy()
{
	if(pNode) pNode->release();
	delete pScene;
}
//--------------------------------------------------------------
void SceneProxy::load()
{
}
//--------------------------------------------------------------
void SceneProxy::unload()
{
}
//--------------------------------------------------------------
void SceneProxy::update()
{
	if(pScene) pScene->update();
}
//--------------------------------------------------------------
void SceneProxy::draw()
{
	if(pScene != NULL){
		pScene->draw();
	}
	else
	{
		ofBackground(190, 190, 190);	
		//Draw the name of the scene
		ofSetColor(70, 70, 70);		
		pFont->drawString(name, 20, 40);
	}
}