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

	ShiftRegister74HC595 by Timo Denk
		- Can be installed from Arduino IDE Library Manager.
		- https://shiftregister.simsso.de
*/

/*
	If you want debugging messages printed to the serial monitor, enable the serial monitor and
	uncomment the line:
	#define BLINKDEBUG
*/

#ifndef BLINKBASE_H
#define BLINKBASE_H

#define BLINKDEBUG

#include <Arduino.h>
#include "SoftTimers.h"

class BlinkBase
{
	// Constructors.
	protected:
		// Constructor.
		BlinkBase(unsigned int pin, unsigned int delay);
		BlinkBase(unsigned int pin, unsigned int delays[], unsigned int numberOfDelays);

	public:
		// Default destructor.
		~BlinkBase();

	public:
		// Initialization.  Run this functions in your "setup" routine.
		virtual void begin();

		//  Loop function.  Run this in your "loop" routine.
		void update();

		// Manual control of pins.
		virtual void setPins(uint8_t level) = 0;

	// Helper functions for the derived classes.  The user does not need to worry about these.
	protected:
		// Returns the current level (HIGH or LOW) to use for setting the pin.
		uint8_t getActiveLevel();

	// Debugging functions.  Only used if the debug preprocessor definition is declared (see comments at top of file).
	protected:
		#ifdef BLINKDEBUG
		// Print the state of a pin.
		void printPinState(int pin, uint8_t level);
		#endif

	// Private functions.  The user need not worry about these.
	private:
		// Do the work.  Each derived class must implement its own behavior.
		virtual void updatePins() = 0;

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