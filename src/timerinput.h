/*
 * TimerInput class
 * A timer input will activate on a regular time interval
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */

#ifndef _TIMER_INPUT_H
#define _TIMER_INPUT_H

//Includes
#include "input.h"

//Forward declarations
namespace Poco { namespace XML { class Node; }}

class TimerInput: public Input 
{

public:
	TimerInput();
	TimerInput(Poco::XML::Node* pNode);
	~TimerInput();

	virtual void read();

	virtual Input* create(Poco::XML::Node* pNode);

private:
	long activationTime;
	long interval;

	virtual void updateActivationTime();

};

#endif
