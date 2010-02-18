#ifndef _INPUT_OBSERVER_H
#define _INPUT_OBSERVER_H

//Includes
#include "inputevent.h"

class InputObserver {

	public:
		InputObserver();
		~InputObserver();

		virtual void trigger(InputEvent event)=0;
};

#endif
