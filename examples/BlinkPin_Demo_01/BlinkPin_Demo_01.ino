#include "BlinkPin.h"

// DESCRIPTION
// This example shows the basics of how to blink a pin.

// CONFIGURATION
// These items should be set to the values according to how you set your Arduino up.
int pinToBlink   	= 7;

// Set these items to your desired values.
int blinkDely		= 1000;

// EXAMPLE STARTS HERE
// Now we use all the items from the configuration section to build and run the example.
BlinkPin blinker(pinToBlink, blinkDely);

void setup()
{
	Serial.begin(9600);
  	
	blinker.begin();
}

void loop()
{
	blinker.update();
}