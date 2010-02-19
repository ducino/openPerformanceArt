#ifndef _OUTPUT_H
#define _OUTPUT_H

//Forward declarations
namespace Poco { namespace XML { class Node; } }

class Output 
{

public:
	Output();
	~Output();

	/*
	 * Draw the output
	 */
	virtual void draw()=0;

	/*
	 * Create an instance of this class given an XML description
	 */
	virtual Output* create(Poco::XML::Node* pNode)=0;
};

#endif
