#include "BlinkPin.h"

// DESCRIPTION
// This example shows the blinks a pin with differents length of time for the on and off states.

// CONFIGURATION
// These items should be set to the values according to how you set your Arduino up.
int pinToBlink   			= 7;

// The numberOfDelays must be set to the number of entries in blinkDelays.  Set the
int numberOfDelays      	= 6;
unsigned int blinkDelys[] 	= {200, 200, 200, 200, 1500, 200};

// EXAMPLE STARTS HERE
// Now we use all the items from the configuration section to build and run the example.
BlinkPin blinker(pinToBlink, blinkDelys, numberOfDelays);

void setup()
{
	Serial.begin(9600);
  	
	blinker.begin();
}

void loop()
{
	blinker.update();
}