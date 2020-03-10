/*
	The MIT License (MIT)
	
	Copyright (c) 2019 Lance A. Endres
	
	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
	Library for blinking (turning on and off) Arduino pins.

	This is the base class which holds common functionality.  It is considered an
	abstract class and should not be instantiated.
*/

/*
	You must have the following libraries to run this software.

	SoftTimers by Antoine Beauchamp
		- Be careful to get the right library, there are several timer libraries and even more than one "SoftTimer" library.
		- Can be installed from Arduino IDE Library Manager.
		- https://github.com/end2endzone/SoftTimers
*/

/*
	If you want debugging messages printed to the serial monitor, enable the serial monitor and
	use the following line in your file:
	
	#define BLINKDEBUG
*/

#ifndef BLINKBASE_H
#define BLINKBASE_H

#include <Arduino.h>
#include "SoftTimers.h"

class BlinkBase
{
	// Constructors.
	public:
		// Constructor.
		BlinkBase(unsigned int pin, unsigned int delay);

		// Default destructor.
		~BlinkBase();


	// Setup functions.  Create your instance and run these functions in your "setup" routine.
	public:
		// Final initialization.
		void begin();


	// Optional settings.
	public:
		// Loop functions.  Run these functions in your "loop" routine.
	public:
		// Entry point to the battery meter.  Checks for any state changes and updates accordingly.
		void update();

		// Helper functions for the derived classes.
	protected:
		uint8_t getActiveLevel();

		// Protected debugging functions.  Used by the derived classes.
	protected:
	#ifdef BLINKDEBUG

		// Print the state of a pin.
		void printPinState(int pin, bool on);

	#endif

		// Private functions.  The user need not worry about these.
	private:
		// Do the work.  Each derived class must implement its own behavior.
		virtual void updateBlink() = 0;


		// Members / variables.
		// The underscore denotes a variable that belongs to the class (not a local variable).
	protected:
		// Output pins.
		unsigned int*	_pins;
		unsigned int	_numberOfPins;

		// Delays.
		unsigned int*	_delays;
		unsigned int 	_numberOfDelays;
		unsigned int 	_currentDelay;

		// Initialization level for pins.  Pins are set to this value in "begin" and then after
		// the first time interval is completed, the pin is set to the opposite.
		uint8_t			_startLevel;
		uint8_t			_secondLevel;


	private:
		// Used to remember the state.
		bool 			_on;

		// Timer.
		SoftTimer 		_updateTimer;
};

#endif