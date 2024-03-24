#include <Arduino.h>

// Configs (Server details)
#define LED_GPIO 21

#include <Hard-Stuff-Onboard-LED.hpp>

void setup()
{
    LED::init(0x999922);

    delay(1000);
    LED::toggleLED();
    delay(1000);
    LED::setLEDRGB(0xff0000);
    LED::toggleLED();
}

void loop()
{
    delay(1000);
    LED::toggleLED();
}