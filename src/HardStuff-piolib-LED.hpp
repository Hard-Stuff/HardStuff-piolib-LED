#pragma once
// Libs
#include <FastLED.h>

#ifndef LED_GPIO
#pragma message("LED::No LED_GPIO defined, using default of gpio 21")
#define LED_GPIO 21
#endif

namespace LED
{
    CRGB leds[1];
    static CRGB lastColour = CRGB(255, 255, 255); // Initialize with a default colour

    void setLEDRGB(uint32_t colour)
    {
        int R = (colour >> 8) & 0xFF;  // Extract the red component
        int G = (colour >> 16) & 0xFF; // Extract the green component
        int B = colour & 0xFF;         // Extract the blue component
        leds[0] = CRGB(R, G, B);
        lastColour = CRGB(R, G, B); // Set the LED colour
        FastLED.show();
    }

    bool init(uint32_t start_colour = 0xffffff)
    {
        pinMode(LED_GPIO, OUTPUT);
        digitalWrite(LED_GPIO, LOW);
        FastLED.addLeds<NEOPIXEL, LED_GPIO>(leds, 1); // GRB ordering is assumed
        setLEDRGB(start_colour);
        return true;
    }

    void toggleLED()
    {
        leds[0] = (leds[0] == lastColour) ? CRGB::Black : lastColour;
    }
}
