#include <Arduino.h>

/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html

   This example code is in the public domain.
*/

const int ledPin = 13;

void setup() {
    // initialize the digital pin as an output.
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);   // set the LED on
    delay(1000);                  // wait for a second
    digitalWrite(ledPin, LOW);    // set the LED off
    delay(1000);                  // wait for a second
}
