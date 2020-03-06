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
  This class is for an output attached directly to an Arduino, there is a separate
  class for pins that are on a shift register.
*/

/*
  See "BlinkBase.h" for more information.
*/

#ifndef BATTERYMETERPINS_H
#define BATTERYMETERPINS_H

#include <Arduino.h>
#include "BlinkBase.h"

class BlinkPin : public BlinkBase
{
  // Constructors.
  public:
	// Constructor.
	BlinkPin(unsigned int pin, unsigned int delay);

	// Default destructor.
	~BlinkPin();


  // Setup functions.  Create your instance and run these functions in your "setup" routine.
  public:


  // Private functions.  The user need not worry about these.
  private:
	// Do the work.  Each derived class must implement its own behavior.
	virtual void updateBlink();


  // Members / variables.
  // The underscore denotes a variable that belongs to the class (not a local variable).
  private:
};

#endif
