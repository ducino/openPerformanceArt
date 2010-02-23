/*
 * InputManager class
 *
 * Copyright 2010 Johan Robben
 * This code is distributed under the terms of the GNU General Public License
 */
#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

//Includes
#include <vector>

//Forward declarations
class Input;
class InputObserver;

using namespace std;

class InputManager {

public:
	static InputManager& the()
	{
		static InputManager singleton;
		return singleton;
	}

private:
	InputManager() {};                                 // Private constructor
	~InputManager() {};
	InputManager(const InputManager&);                 // Prevent copy-construction
	InputManager& operator=(const InputManager&);      // Prevent assignment

public:

	/*
	 * Read all inputs
	 */
	void read();

	/*
	 * Add an input
	 */
	void add(Input* input);

	/*
	 * Add multiple inputs
	 */
	void add(vector<Input*>& inputs);

	/*
	 * Register the observer with the input with the given name
	 */
	void registerObserver(string inputName, InputObserver* observer);

	/*
	 * Unregister all observers
	 */
	void unregisterAllObservers();

private:
	vector<Input*> inputs;
};

#endif
