/***************************************
 * A collection of utility methods
 * for xml and string operations
 ***************************************/

#ifndef _UTILS_H
#define _UTILS_H

//Includes
#include <iostream>
#include "ofMain.h"

//Forward declarations
namespace Poco { namespace XML {class Node;} }

using namespace std;

/*
 * Check if the tag of the node matches the given name
 */
bool match(Poco::XML::Node* pNode, string tag);

/*
 * Get a string attribute of a node given its name
 * The defaultvalue will be returned when the attribute does not exist
 */
string getStringAttribute(Poco::XML::Node* pNode, string name, string defaultValue);

/*
 * Get an int attribute of a node given its name
 * The defaultvalue will be returned when the attribute does not exist
 */
int getIntAttribute(Poco::XML::Node* pNode, string name, int defaultValue);

/*
 * Get a color attribute of a node given its name
 * The defaultvalue will be returned when the attribute does not exist
 */
ofColor getColorAttribute(Poco::XML::Node* pNode, string name, ofColor defaultValue);

/*
 * Get a 2D coordinates attribute of a node given its name
 * The defaultvalue will be returned when the attribute does not exist
 */
ofPoint get2DCoordAttribute(Poco::XML::Node* pNode, string name, ofPoint defaultValue);

/*
 * Check if two strings are the same (ignoring the case)
 */
bool equalsIgnoreCase(string one, string other);

/*
 * Check if two characters are the same (ignoring the case)
 */
bool caseInsensitiveCharCompare(char a, char b);

#endif