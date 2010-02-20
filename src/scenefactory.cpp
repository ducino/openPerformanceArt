#include "scenefactory.h"
#include "sceneproxy.h"
#include "inputmanager.h"
#include "input.h"
#include "output.h"
#include "scene.h"
#include "parseutils.h"

#include "Poco/DOM/DOMParser.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/NamedNodeMap.h"
#include "Poco/DOM/TreeWalker.h"
#include "Poco/DOM/NodeFilter.h"
#include "Poco/DOM/Attr.h"
#include "Poco/DOM/AutoPtr.h"
#include "Poco/SAX/InputSource.h"
#include "Poco/Exception.h"
#include "Poco/Path.h"
#include <iostream>

using Poco::XML::DOMParser;
using Poco::XML::InputSource;
using Poco::XML::Document;
using Poco::XML::NamedNodeMap;
using Poco::XML::TreeWalker;
using Poco::XML::NodeFilter;
using Poco::XML::Node;
using Poco::XML::Attr;
using Poco::XML::AutoPtr;
using Poco::Exception;
using Poco::Path;

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
void SceneFactory::load(string xmlFile, vector<SceneProxy*>& scenes)
{
	vector<Input*> inputs;
	try
	{
		//Parse the xml file
		DOMParser parser;
		Document* pDoc = parser.parse(xmlFile);

		//Add the path of the document as an attribute of the first child of the document
		//this to ensure we can always load an included xml file relative to this document
		{
			Path path(xmlFile);
			Attr* attr = pDoc->createAttribute("_path");
			attr->setNodeValue(path.makeAbsolute().toString());
			pDoc->firstChild()->attributes()->setNamedItem(attr);
		}

		//Save the document in memory
		documents.push_back(pDoc);
		
		//Iterate the children of the document
		TreeWalker it(pDoc, NodeFilter::SHOW_ALL);
		Node* pNode = it.nextNode();
		while (pNode)
		{
			cout << "Doc: " << pNode->nodeName() << endl;
			if(match(pNode, "root"))
			{
				pNode = it.firstChild();
			}
			else if(match(pNode, "scene"))
			{
				scenes.push_back(new SceneProxy(pNode));
			}
			else if(match(pNode, "input"))
			{
				createInputs(pNode, inputs);
			}
			else if(match(pNode, "include"))
			{
				load(getAbsolutePath(pNode, getStringAttribute(pNode, "path", "")), scenes);
			}

			pNode = it.nextSibling();
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
	TreeWalker it(pRootNode, NodeFilter::SHOW_ELEMENT);
	Node* pNode = it.nextNode();
	
	cout << "Inputs" << endl;
	while (pNode)
	{
		cout << "- " << pNode->nodeName() << endl;
		Input* input = inputMap[pNode->nodeName()];
		if( input != NULL)
		{
			inputs.push_back(input->create(pNode));
			//cout << "Created input with name : " << pNode->nodeName() << endl;
		}
		else
		{
			cerr << "Not recognized: " << pNode->nodeName() << endl;
		}

		pNode = it.nextSibling();
	}
}
//--------------------------------------------------------------
void SceneFactory::loadOutputs(vector<Output*>& outputs, Poco::XML::Node* pRootNode)
{
	TreeWalker it(pRootNode, NodeFilter::SHOW_ELEMENT);
	Node* pNode = it.nextNode();
	
	cout << "Outputs" << endl;
	while (pNode)
	{
		cout << "- " << pNode->nodeName() << endl;
		Output* output = outputMap[pNode->nodeName()];
		if( output != NULL)
		{
			outputs.push_back(output->create(pNode));
			//cout << "Created output with name : " << pNode->nodeName() << endl;
		}
		else
		{
			cerr << "Not recognized: " << pNode->nodeName() << endl;
		}

		pNode = it.nextSibling();
	}
}