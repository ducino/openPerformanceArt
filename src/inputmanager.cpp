#include "inputmanager.h"
#include "input.h"
#include "parseutils.h"

//--------------------------------------------------------------
void InputManager::read()
{
	for( vector<Input*>::const_iterator iter = inputs.begin();
		iter != inputs.end(); ++iter ) 
	{
		(*iter)->read();
	}
}
//--------------------------------------------------------------
void InputManager::add(Input* input)
{
	inputs.push_back(input);
}
//--------------------------------------------------------------
void InputManager::add(vector<Input*>& inputs)
{
	for( vector<Input*>::const_iterator iter = inputs.begin();
		iter != inputs.end(); ++iter ) 
	{
		add(*iter);
	}
}
//--------------------------------------------------------------
void InputManager::registerObserver(string inputName, InputObserver* observer)
{
	for( vector<Input*>::const_iterator iter = inputs.begin();
		iter != inputs.end(); ++iter ) 
	{
		if(equalsIgnoreCase((*iter)->getName(), inputName))
		{
			(*iter)->add(observer);
		}
	}
}
//---------------------------------------------------------------
void InputManager::unregisterAllObservers()
{
	for( vector<Input*>::const_iterator iter = inputs.begin();
		iter != inputs.end(); ++iter ) 
	{
		(*iter)->removeAllObservers();		
	}
}