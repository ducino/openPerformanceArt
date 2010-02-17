#include "scenefactory.h"

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
			std::cout << pNode->nodeName() << ":" << pNode->nodeValue() << std::endl;
			pNode = it.nextNode();
		}
	}
	catch (Exception& exc)
	{
		std::cerr << exc.displayText() << std::endl;
	}
}