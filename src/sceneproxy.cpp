/*
 * SceneProxy implementation
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#include "sceneproxy.h"
#include "scene.h"
#include "parseutils.h"

#include "ofMain.h"
#include "Poco/DOM/Node.h"
#include "Poco/DOM/NamedNodeMap.h"

using Poco::XML::Node;
using Poco::XML::NamedNodeMap;

//--------------------------------------------------------------
SceneProxy::SceneProxy(Node* pRootNode)
: pScene(NULL)
{
	//At first I used cloneNode here, but this didn't seem to work
	//Now I'll just assume the xml config is kept in memory
	pNode = pRootNode;
	
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
	if(pScene == NULL)
	{
		pScene = new Scene(pNode);
	}
}
//--------------------------------------------------------------
void SceneProxy::unload()
{
	delete pScene;
	pScene = NULL;
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

		int gray = (ofGetElapsedTimeMillis()/10)%512;
		gray = (gray>=256)? 255 - (gray-256) : gray;
		ofSetColor(gray, gray, gray);
		string s = "<Press Enter to Load>";
		pFont->drawString("<Press Enter to Load>", ofGetWidth()/2-pFont->stringWidth(s)/2, ofGetHeight()/2);
	}
}