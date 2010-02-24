/*
 * OutputCollection class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _OUTPUT_COLLECTION_H
#define _OUTPUT_COLLECTION_H

//Includes
#include "inputobserver.h"
#include <vector>

using namespace std;

class OutputCollection: public InputObserver
{

public:
	OutputCollection();
	OutputCollection(Poco::XML::Node* pNode);
	virtual ~OutputCollection();

	virtual void update();

protected:
	vector<Output*> outputs;

	void drawAllOutputs();
};

#endif