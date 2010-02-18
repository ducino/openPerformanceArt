/*********************************************************
 * A timer input will activate on a regular time interval
 *********************************************************/

#ifndef _TIMER_INPUT_H
#define _TIMER_INPUT_H

//Includes
#include "input.h"
#include "ofMain.h"

//Forward declarations
namespace Poco { namespace XML { class Node; }}

class TimerInput: public Input {

	public:
		TimerInput(Poco::XML::Node* pNode);
		~TimerInput();

		virtual void read();

	private:
		long activationTime;
		long interval;

		virtual void updateActivationTime();

};

#endif
