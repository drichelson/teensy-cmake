#include <Arduino.h>

#define USE_OCTOWS2811

#include <OctoWS2811.h>
#include <FastLED.h>

#define NUM_LEDS_PER_STRIP 244
#define NUM_STRIPS 8

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];
const int onBoardLedPin = 13;


void setup() {
    delay(2000);
    Serial.begin(115200);
    pinMode(onBoardLedPin, OUTPUT);
    digitalWrite(onBoardLedPin, HIGH);

    LEDS.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
    LEDS.setBrightness(32);
}

void loop() {
    digitalWrite(onBoardLedPin, HIGH);   // set the LED on
    delay(1000);                  // wait for a second

    static uint8_t hue = 0;
    for (int i = 0; i < NUM_STRIPS; i++) {
        for (int j = 0; j < NUM_LEDS_PER_STRIP; j++) {
            leds[(i * NUM_LEDS_PER_STRIP) + j] = CHSV((32 * i) + hue + j, 192, 255);
        }
    }

    // Set the first n leds on each strip to show which strip it is
    for (int i = 0; i < NUM_STRIPS; i++) {
        for (int j = 0; j <= i; j++) {
            leds[(i * NUM_LEDS_PER_STRIP) + j] = CRGB::Red;
        }
    }

    hue++;

    LEDS.show();
    LEDS.delay(10);
    digitalWrite(onBoardLedPin, LOW);    // set the LED off
    delay(1000);                  // wait for a second
}
