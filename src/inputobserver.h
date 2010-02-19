#ifndef _INPUT_OBSERVER_H
#define _INPUT_OBSERVER_H

//Includes
#include "inputevent.h"

//Forward declarations
namespace Poco { namespace XML { class Node; } }

class InputObserver 
{
public:
	InputObserver();
	InputObserver(Poco::XML::Node* pNode);
	~InputObserver();

	void trigger(InputEvent& event);

protected:
	virtual void triggerInternal(InputEvent& event)=0;

	/*
	 * Check if this observer is active
	 * Active means it has been triggered recently
	 */
	bool isActive();

private:
	long previousTriggerTime;
	long duration;
};

#endif
