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
	~OutputCollection();

protected:
	vector<Output*> outputs;

	void drawAllOutputs();
};

#endif