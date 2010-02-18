#ifndef _INPUT_H
#define _INPUT_H

//Includes
#include <vector>
#include "inputevent.h"

//Forward declarations
class InputObserver;

using namespace std;

class Input 
{

public:
	Input();
	~Input();

	/*
	 * Read the input, notifying observers when something of interest has happened
	 */
	virtual void read()=0;

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
	void notifyObservers(InputEvent event);

private:

	//The list of observers listening to this input
	vector<InputObserver*> observers;
};

#endif
