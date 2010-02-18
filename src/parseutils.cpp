#include "parseutils.h"

#include "ofMain.h"

#include "Poco/DOM/Node.h"
#include "Poco/DOM/AutoPtr.h"
#include "Poco/DOM/NamedNodeMap.h"

using Poco::XML::Node;
using Poco::XML::AutoPtr;
using Poco::XML::NamedNodeMap;

//--------------------------------------------------------------
bool match(Poco::XML::Node* pNode, string tag)
{
	string nodeTag = pNode->nodeName();
	return equalsIgnoreCase(nodeTag, tag);
}
//--------------------------------------------------------------
string getStringAttribute(Poco::XML::Node* pNode, string name, string defaultValue)
{
	AutoPtr<NamedNodeMap> pMap = pNode->attributes();
	Node* pAttributeNode = pMap->getNamedItem(name);
	if(pAttributeNode)
	{
		return pAttributeNode->nodeValue();
	}
	else
	{
		return defaultValue;
	}
}
//--------------------------------------------------------------
int getIntAttribute(Poco::XML::Node* pNode, string name, int defaultValue)
{
	AutoPtr<NamedNodeMap> pMap = pNode->attributes();
	Node* pAttributeNode = pMap->getNamedItem(name);
	if(pAttributeNode)
	{
		return ofToInt(pAttributeNode->nodeValue());
	}
	else
	{
		return defaultValue;
	}	
}
//--------------------------------------------------------------
bool equalsIgnoreCase(string one, string other)
{
	return ((one.size( ) == other.size( )) &&
             equal(one.begin( ), one.end( ), other.begin( ), caseInsensitiveCharCompare));
}


//--------------------------------------------------------------
bool caseInsensitiveCharCompare(char a, char b) {
   return(tolower(a) == tolower(b));
}