/*

Example sketch 01

BLINKING A LED

  Turn an LED on for one second, off for one second,
  and repeat forever.

Hardware connections:

  Most Arduinos already have an LED and resistor connected to
  pin 13, so you may not need any additional circuitry.

  But if you'd like to connect a second LED to pin 13, or use
  a different pin, follow these steps:

    Connect the positive side of your LED (longer leg) to Arduino
    digital pin 13 (or another digital pin, don't forget to change
    the code to match).
  
    Connect the negative side of your LED (shorter leg) to a 
    330 Ohm resistor (orange-orange-brown). Connect the other side
    of the resistor to ground.

    pin 13 _____ + LED - _____ 330 Ohm _____ GND
	
    (We always use resistors between the Arduino and and LEDs
    to keep the LEDs from burning out due to too much current.)

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Welcome to Arduino!

// If you're brand-new to this, there will be some new things to
// learn, but we'll jump right in and explain things as we go.

// The Arduino is a tiny computer that runs programs called
// "sketches". These are text files written using instructions
// the computer understances. You're reading a sketch right now.

// Sketches have computer code in them, but also (hopefully)
// "comments" that explain what the code does. Comments and code
// will have different colors in the editor so you can tell them
// apart.

// This is a comment - anything on a line after "//" is ignored
// by the computer.

/* This is also a comment - this one can be multi-line, but it
must start and end with these characters */

// A "function" is a named block of code, that performs a specific,
// well, function. Many useful functions are already built-in to
// the Arduino; others you'll name and write yourself for your
// own purposes.

// All Arduino sketches MUST have two specific functions, named
// "setup()" and "loop()". The Arduino runs these functions
// automatically when it starts up or if you press the reset
// button. You'll typically fill these function "shells" with your
// own code. Let's get started!


// The setup() function runs once when the sketch starts.
// You'll use it for things you need to do first, or only once:


void setup()
{
  // The Arduino has 13 digital input/output pins. These pins
  // can be configured as either inputs or outputs. We set this
  // up with a built-in function called pinMode().

  // The pinMode() function takes two values, which you type in
  // the parenthesis after the function name. The first value is
  // a pin number, the second value is the word INPUT or OUTPUT.
  
  // Here we'll set up pin 13 (the one connected to a LED) to be
  // an output. We're doing this because we need to send voltage
  // "out" of the Arduino to the LED.

  pinMode(13, OUTPUT);

  // By the way, the Arduino offers many useful built-in functions
  // like this one. You can find information on all of them at the
  // Arduino website: http://arduino.cc/en/Reference
}


// After setup() finishes, the loop() function runs over and over
// again, forever (or until you turn off or reset the Arduino).
// This is usually where the bulk of your program lives:


void loop()
{

  int dot = 300;
  int dash = dot * 3;


  digitalWrite(13, HIGH);
  delay(dot);
  digitalWrite(13, LOW);
  delay(dot);    
  digitalWrite(13, LOW);
  delay(dot);      
  digitalWrite(13, HIGH);
  delay(dot);
  digitalWrite(13, LOW);
  delay(dash);  
  digitalWrite(13, HIGH);
  delay(dash);
  digitalWrite(13, LOW);
  delay(dash);         
  digitalWrite(13, HIGH);
  delay(dash);
  digitalWrite(13, LOW);
  delay(dash);  


}

