#include <Arduino.h>

// Configs (Server details)
#define LED_GPIO 21

#include <Hard-Stuff-Onboard-LED.hpp>

void setup()
{
    // Turn to ~purprle
    LED::init(0x992299);

    delay(1000);

    // Turn off
    LED::toggleLED();
    delay(1000);

    // Turn to red
    LED::setLEDRGB(0xff0000);
    // Immediately turn off (because setLEDRGB turns it on)
    LED::toggleLED();
}

void loop()
{
    delay(1000);
    // Toggle forever
    LED::toggleLED();
}