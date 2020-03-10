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

template <uint8_t numberOfShiftRegisters>
BlinkShiftRegister<numberOfShiftRegisters>::BlinkShiftRegister(ShiftRegister74HC595<numberOfShiftRegisters>* shiftRegister, unsigned int pin, unsigned int delay) :
    BlinkBase(pin, delay),
    _shiftRegister(shiftRegister)
{
}

template <uint8_t numberOfShiftRegisters>
BlinkShiftRegister<numberOfShiftRegisters>::BlinkShiftRegister(ShiftRegister74HC595<numberOfShiftRegisters>* shiftRegister, unsigned int pin, unsigned int delays[], unsigned int numberOfDelays) :
    BlinkBase(pin, delays, numberOfDelays),
    _shiftRegister(shiftRegister)
{
}

template <uint8_t numberOfShiftRegisters>
BlinkShiftRegister<numberOfShiftRegisters>::~BlinkShiftRegister()
{
}

template <uint8_t numberOfShiftRegisters>
void BlinkShiftRegister<numberOfShiftRegisters>::updateBlink()
{
	uint8_t level = getActiveLevel();

	for (int i = 0; i < _numberOfPins; i++)
	{
		_shiftRegister->setNoUpdate(_pins[i], level);
	}

	// Now that all the bit values are set for the lights, activate them.
	_shiftRegister->updateRegisters();
}