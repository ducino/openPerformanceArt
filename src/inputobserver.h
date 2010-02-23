/*
 * InputObserver class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _INPUT_OBSERVER_H
#define _INPUT_OBSERVER_H

//Includes
#include "inputevent.h"
#include "output.h"

//Forward declarations
namespace Poco { namespace XML { class Node; } }

class InputObserver: public Output
{
public:
	InputObserver();
	InputObserver(Poco::XML::Node* pNode);
	~InputObserver();

	virtual void trigger(InputEvent& event)=0;
};

#endif
