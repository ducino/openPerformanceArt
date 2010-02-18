#include "input.h"
#include "inputobserver.h"

//--------------------------------------------------------------
Input::Input()
{
}
//--------------------------------------------------------------
Input::~Input()
{
}
//--------------------------------------------------------------
void Input::add(InputObserver* observer)
{
	observers.push_back(observer);
}
//--------------------------------------------------------------
void Input::removeAllObservers()
{
	observers.clear();
}
//--------------------------------------------------------------
void Input::notifyObservers(InputEvent event)
{
	for( vector<InputObserver*>::const_iterator iter = observers.begin();
		iter != observers.end(); ++iter ) 
	{
		(*iter)->trigger(event);
	}
}