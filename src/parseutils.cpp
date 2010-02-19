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
ofColor getColorAttribute(Poco::XML::Node* pNode, string name, ofColor defaultValue)
{
	AutoPtr<NamedNodeMap> pMap = pNode->attributes();
	Node* pAttributeNode = pMap->getNamedItem(name);
	if(pAttributeNode)
	{
		char c[20];
		if(pAttributeNode->nodeValue().size() >= 20)
		{
			return defaultValue;
		}

		strcpy(c, pAttributeNode->nodeValue().c_str());
		char* red = strtok (c, " ,");

		if(red == NULL)
		{
			return defaultValue;
		}

		char* green = strtok (NULL," ,");
				
		if(green == NULL)
		{
			return defaultValue;
		}

		char* blue = strtok (NULL," ,");
				
		if(blue == NULL)
		{
			return defaultValue;
		}

		ofColor color;
		color.r = ofToInt(red);
		color.g = ofToInt(green);
		color.b = ofToInt(blue);

		return color;
	}
	else
	{
		return defaultValue;
	}
}
//--------------------------------------------------------------
ofPoint get2DCoordAttribute(Poco::XML::Node* pNode, string name, ofPoint defaultValue)
{
	AutoPtr<NamedNodeMap> pMap = pNode->attributes();
	Node* pAttributeNode = pMap->getNamedItem(name);
	if(pAttributeNode)
	{
		char c[20];
		if(pAttributeNode->nodeValue().size() >= 20)
		{
			return defaultValue;
		}

		strcpy(c, pAttributeNode->nodeValue().c_str());
		char* x = strtok (c, " ,");

		if(x == NULL)
		{
			return defaultValue;
		}

		char* y = strtok (NULL," ,");
				
		if(y == NULL)
		{
			return defaultValue;
		}

		return ofPoint(ofToInt(x), ofToInt(y));
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
bool caseInsensitiveCharCompare(char a, char b)
{
   return(tolower(a) == tolower(b));
}