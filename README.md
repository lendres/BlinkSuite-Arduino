# BlinkSuite

Library for blinking (turning on and off) or running sequences on Arduino pins.  There are two output options.  The first is for turning on indicators attached to Arduino pins.  The second option outputs through a shift register.  These options are implemented as separate classes.

#### BlinkPin
Blink a pin (or set of pins) connected to Arduino pin(s).

#### BlinkShiftRegister
Blink a pin (or set of pins) connected to Arduino pin through a shift register.


## About the Library
### Github Page

https://github.com/lendres/BlinkSuite-Arduino


### Prerequisites

This library requires the following librarys to run:

* [SoftTimers](https://github.com/end2endzone/SoftTimers) - Time libary by Antoine Beauchamp

* [ShiftRegister74HC595](https://timodenk.com/blog/shift-register-arduino-library/) - ShiftRegister74HC595 Arduino Library


### Installing

For information on installing Arduino libaries, see: [Arduino Libraries](http://www.arduino.cc/en/Guide/Libraries)


## Versioning

We use [SemVer](http://semver.org/) for versioning.

## Authors

* **Lance A. Endres** - [lendres](https://github.com/lendres)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
