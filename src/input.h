/*
 * Input class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _INPUT_H
#define _INPUT_H

//Includes
#include <vector>
#include "inputevent.h"

//Forward declarations
class InputObserver;
namespace Poco { namespace XML { class Node; } }

using namespace std;

class Input 
{

public:
	Input();
	Input(Poco::XML::Node* pNode);
	virtual ~Input();

	/*
	 * Read the input, notifying observers when something of interest has happened
	 */
	virtual void read()=0;

	/*
	 * Get the name of this input
	 */
	string getName() const;

	/*
	 * Create an instance of this class given an XML description
	 */
	virtual Input* create(Poco::XML::Node* pNode)=0;

	/*
	 * Add an observer to this input
	 */
	void add(InputObserver* observer);

	/*
	 * Remove all observers from this input
	 */
	void removeAllObservers();

protected:

	/*
	 * Notify all observers of a given event
	 */
	void notifyObservers(InputEvent* event);

private:

	//The name of this input
	string name;

	//The list of observers listening to this input
	vector<InputObserver*> observers;
};

#endif
