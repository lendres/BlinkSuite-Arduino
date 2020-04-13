#include "ShiftRegister74HC595.h"
#include "BlinkShiftRegister.h"


// DESCRIPTION
// This example shows the basics of how to blink a pin.

// CONFIGURATION
// These items should be set to the values according to how you set your Arduino up.
// Pin (on the shift register) to blink.  Pins are zero based.
int pinToBlink   	= 7;

// Shift register pins.
int dataPin   		= 2; 
int clockPin 	 	= 3;
int latchPin 	 	= 4;

// Set these items to your desired values.
int blinkDely		= 400;

// EXAMPLE STARTS HERE
// Now we use all the items from the configuration section to build and run the example.
// Create the instances.  It is assumed the shift register is managed (and used) elsewhere and
// a pointer to it is passed to the battery meter.
ShiftRegister74HC595<1> shiftRegister(dataPin, clockPin, latchPin);
BlinkShiftRegister<1> blinker(&shiftRegister, pinToBlink, blinkDely);

void setup()
{
	Serial.begin(9600);
	blinker.begin();

	blinker.setPins(HIGH);
	delay(2500);
	blinker.setPins(LOW);
	delay(2500);
}

void loop()
{
	blinker.update();
}