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
    static CRGB lastColor = CRGB(255, 255, 255); // Initialize with a default color
    static bool isOn = false;                    // Static variable to keep track of the LED's state

    void setLEDRGB(uint32_t color)
    {
        int R = (color >> 8) & 0xFF;  // Extract the red component
        int G = (color >> 16) & 0xFF; // Extract the green component
        int B = color & 0xFF;         // Extract the blue component
        leds[0] = CRGB(R, G, B);
        lastColor = CRGB(R, G, B); // Set the LED color
        FastLED.show();
        isOn = true;
    }

    bool init(uint32_t start_color = 0xffffff)
    {
        pinMode(LED_GPIO, OUTPUT);
        digitalWrite(LED_GPIO, LOW);
        FastLED.addLeds<NEOPIXEL, LED_GPIO>(leds, 1); // GRB ordering is assumed
        setLEDRGB(start_color);
        return true;
    }

    void toggleLED()
    {
        if (isOn)
        {
            lastColor = leds[0]; // Turn off the LED and remember its last color
            leds[0] = CRGB::Black;
        }
        else
        {
            leds[0] = lastColor; // Restore the LED to its last color
        }
        FastLED.show(); // Update the LED
        isOn = !isOn;   // Toggle the state
    }

}
