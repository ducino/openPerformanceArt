#include "scenefactory.h"
#include "sceneproxy.h"

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
}
//--------------------------------------------------------------
SceneFactory::~SceneFactory()
{
}
//--------------------------------------------------------------
void SceneFactory::loadScenes(string xmlFile, vector<SceneProxy*>& scenes)
{
	try
	{
		DOMParser parser;
		AutoPtr<Document> pDoc = parser.parse(xmlFile);
		
		NodeIterator it(pDoc, NodeFilter::SHOW_ALL);
		Node* pNode = it.nextNode();
		while (pNode)
		{
			if(match(pNode, "scene"))
			{
				scenes.push_back(new SceneProxy(pNode));
			}

			pNode = it.nextNode();
		}
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
	}
}
//--------------------------------------------------------------
bool caseInsensitiveCharCompare(char a, char b) {
   return(tolower(a) == tolower(b));
}
//--------------------------------------------------------------
bool SceneFactory::match(Node* pNode, string tag)
{
	string nodeTag = pNode->nodeName();
	return((tag.size( ) == nodeTag.size( )) &&
          equal(tag.begin( ), tag.end( ), nodeTag.begin( ), caseInsensitiveCharCompare));
}