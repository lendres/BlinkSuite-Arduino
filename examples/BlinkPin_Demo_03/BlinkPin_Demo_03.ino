#include "BlinkPin.h"

// DESCRIPTION
// This example shows how to use the manual on/off feature of the BlinkPin class.

// CONFIGURATION
// These items should be set to the values according to how you set your Arduino up.
int pinToBlink   			= 7;

// The numberOfDelays must be set to the number of entries in blinkDelays.  Set the
// delays to your desired length.
int numberOfDelays			= 1;
unsigned int blinkDelys[] 	= {400};

// EXAMPLE STARTS HERE
// Now we use all the items from the configuration section to build and run the example.
BlinkPin blinker(pinToBlink, blinkDelys, numberOfDelays);

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