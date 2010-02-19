#include "scenefactory.h"
#include "sceneproxy.h"
#include "inputmanager.h"
#include "input.h"
#include "output.h"
#include "scene.h"
#include "parseutils.h"

#include "Poco/DOM/DOMParser.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/NodeIterator.h"
#include "Poco/DOM/NodeFilter.h"
#include "Poco/DOM/AutoPtr.h"
#include "Poco/SAX/InputSource.h"
#include "Poco/Exception.h"
#include <iostream>

using Poco::XML::DOMParser;
using Poco::XML::InputSource;
using Poco::XML::Document;
using Poco::XML::NodeIterator;
using Poco::XML::NodeFilter;
using Poco::XML::Node;
using Poco::XML::AutoPtr;
using Poco::Exception;

//--------------------------------------------------------------
SceneFactory::SceneFactory()
{
	createInputMap();
	createOutputMap();
}
//--------------------------------------------------------------
SceneFactory::~SceneFactory()
{
	//Clean up the input map
	{
		map<string,Input*>::iterator iter;
		for( iter = inputMap.begin(); iter != inputMap.end(); ++iter ) {
			delete iter->second;
		}
		inputMap.clear();
	}

	//Clean up the output map
	{
		map<string,Output*>::iterator iter;
		for( iter = outputMap.begin(); iter != outputMap.end(); ++iter ) {
			delete iter->second;
		}
		outputMap.clear();
	}

	//Clean up the documents
	{
		vector<Document*>::iterator iter;
		for( iter = documents.begin(); iter != documents.end(); ++iter ) {
			(*iter)->release();
		}
		documents.clear();
	}
}
//--------------------------------------------------------------
void SceneFactory::setXml(string xmlFile)
{
	this->xmlFile = xmlFile;
}
//--------------------------------------------------------------
void SceneFactory::load(vector<SceneProxy*>& scenes)
{
	vector<Input*> inputs;
	try
	{
		DOMParser parser;
		Document* pDoc = parser.parse(xmlFile);
		//Save the document in memory
		documents.push_back(pDoc);
		
		NodeIterator it(pDoc, NodeFilter::SHOW_ALL);
		Node* pNode = it.nextNode();
		while (pNode)
		{
			if(match(pNode, "scene"))
			{
				scenes.push_back(new SceneProxy(pNode));
			}
			else if(match(pNode, "input"))
			{
				createInputs(pNode, inputs);
			}

			pNode = it.nextNode();
		}
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
	}

	InputManager::the().add(inputs);
}
//--------------------------------------------------------------
void SceneFactory::createInputs(Poco::XML::Node* pRootNode, vector<Input*>& inputs)
{
	NodeIterator it(pRootNode, NodeFilter::SHOW_ALL);
	Node* pNode = it.nextNode();
	
	while (pNode)
	{
		Input* input = inputMap[pNode->nodeName()];
		if( input != NULL)
		{
			inputs.push_back(input->create(pNode));
			cout << "Created input with name : " << pNode->nodeName() << endl;
		}

		pNode = it.nextNode();
	}
}
//--------------------------------------------------------------
void SceneFactory::loadOutputs(vector<Output*>& outputs, Poco::XML::Node* pRootNode)
{
	NodeIterator it(pRootNode, NodeFilter::SHOW_ALL);
	Node* pNode = it.nextNode();
	
	while (pNode)
	{
		Output* output = outputMap[pNode->nodeName()];
		if( output != NULL)
		{
			outputs.push_back(output->create(pNode));
			cout << "Created output with name : " << pNode->nodeName() << endl;
		}

		pNode = it.nextNode();
	}
}