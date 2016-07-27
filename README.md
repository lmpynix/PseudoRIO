##PseudoRio
PseudoRio is a reference software package for the RoboPi robot controller.
The RoboPi is designed as a drop-in replacement for an NI RoboRIO, for FRC teams
who wish to continue to use their existing robots without having to re-purchase a RoboRIO each
competition season.
####What's in the software?
There are two sides to the RoboPi infrastructure, client (RoboPi itself) and server (RoboPi controller).  As a result, there are two different software packages, represented here as ClientSide and ServerSide.  ServerSide consists mostly of a core which sends joystick inputs to the RoboPi, but will also (in the near future) implement a GUI akin to the FRC dashboard.  ClientSide consists of software both for the Raspberry Pi and for the Arduino Micro in the RoboPi.  The firmware for the Arduino is mostly an implementation of Firmata, probably with very little difference from the base provided by the Arduino IDE.  The software for the Raspberry Pi will consist of Firmata drivers, CAN drivers, and a simple program to drive a 2,4, or 8 motor robot. It will also consist of an API to ease programming of other robot features, using all comunications protocols.
####Can I help?
Yes, please do.