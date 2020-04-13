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

#include "BlinkBase.h"

BlinkBase::BlinkBase(unsigned int pin, unsigned int delay) :
	_pins(new unsigned int[1]{pin}),
	_numberOfPins(1),
	_delays(new unsigned int[1]{delay}),
	_numberOfDelays(1),
	_currentDelay(0),
	_startLevel(HIGH),
	_secondLevel(LOW),
	_on(false)
{
}

BlinkBase::BlinkBase(unsigned int pin, unsigned int delays[], unsigned int numberOfDelays) :
	_pins(new unsigned int[1]{pin}),
	_numberOfPins(1),
	_delays(new unsigned int[numberOfDelays]),
	_numberOfDelays(numberOfDelays),
	_currentDelay(0),
	_startLevel(HIGH),
	_secondLevel(LOW),
	_on(false)
{
	for (unsigned int i = 0; i < _numberOfDelays; i++)
	{
		_delays[i] = delays[i];
	}	
}

BlinkBase::~BlinkBase()
{
	if (_pins)
	{
		delete[] _pins;
	}

	if (_delays)
	{
		delete[] _delays;
	}
}

void BlinkBase::begin()
{
	_updateTimer.setTimeOutTime(_delays[0]);
	_updateTimer.reset();

	// If we are debugging, print info.
	#ifdef BLINKDEBUG
		Serial.print("[Blink] Pins:");
		for (unsigned int i = 0; i < _numberOfPins; i++)
		{
			Serial.print(" ");
			Serial.print(_pins[i]);
		}

		Serial.println("");
		Serial.print("[Blink] Delays:");
		for (unsigned int i = 0; i < _numberOfDelays; i++)
		{
			Serial.print(" ");
			Serial.print(_delays[i]);
		}

		// Print end of line since we don't return after printing the pins above.
		Serial.println("");
	#endif
}

void BlinkBase::update()
{
	if (_updateTimer.hasTimedOut())
	{
		_on = !_on;

		updatePins();

		// Increment the delay index and reset if we are at the end.
		_currentDelay++;
		if (_currentDelay == _numberOfDelays)
		{
			_currentDelay = 0;
		}

		#ifdef BLINKDEBUG
			Serial.print("[Blink] Delay Number: ");
			Serial.println(_currentDelay);

			Serial.print("[Blink] Delay Value: ");
			Serial.println(_delays[_currentDelay]);
		#endif

		_updateTimer.setTimeOutTime(_delays[_currentDelay]);
		_updateTimer.reset();
	}
}

uint8_t BlinkBase::getActiveLevel()
{
	return _on ? _secondLevel : _startLevel;
}

#ifdef BLINKDEBUG
void BlinkBase::printPinState(int pin, uint8_t level)
{
	Serial.print("[Blink] Pin: ");
	Serial.print(_pins[pin]);
	Serial.print("    Level: ");
	Serial.println(level);
}
#endif