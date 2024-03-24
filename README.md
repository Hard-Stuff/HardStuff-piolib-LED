# **Hard Stuff** bricks: LED wrapper

This PlatformIO brick _(a non-classable wrapper around a `lib`)_ is designed to abstract complexity away from using FastLED, specifically for single LED applications (such as the controllable LED on most ESP32 Dev boards). This means:

-   calling high-level functions rather than low-level functions (e.g. `setLEDRGB` instead of unpacking the colours individually then applying `leds[0] = CRGB(R, G, B)` then `.show()`ing the colour etc...)

## Usage

Hard Stuff bricks are written as namespaces. This is because any given project will likely only have one single-use LED brick (if you needed more LEDs you'd also likely need finer fidelity of functionality, so would use [FastLED](https://github.com/FastLED/FastLED) directly).

### Basic Example

All functionality and classes are available within the `LED` namespace.

```cpp
#include <Hard-Stuff-Onboard-LED.hpp>

void setup()
{
    LED::init();              // Assumes default pin (unless specified otherwise)
    LED::setLEDRGB(0xff0000); // Red, set as 0xRRGGBB
}

void loop()
{
    delay(1000);
    LED::toggleLED();
}
```

### `#define`s to be aware of

You can modify the behaviour of the client and SIM7600 via the standardised defines.

```cpp
// Optional defines
#define LED_GPIO number // the GPIO pin used for your dev board's LED. This is 21 on quite a few boards.
```

### Functions available

-   `init()` initialises the LED for use, and turns it on to the `start_colour` (default is white).
-   `setLEDRGB(0xRRGGBB)` sets the colour of the LED (if it is off, it turns it on too).
-   `toggleLED()` quickly turns the LED on/off depending on its previous state.

### Dependencies

-   fastled/FastLED

## Compabibility and testing

This library has been tested on the ESP32S3 with a SIMCOM SIM7600G for various purposes include OTA updates, MQTT to AWS IoT Core, and HTTP requests to Airtable, AWS, and Wiremock.

## Hard Stuff

Hard Stuff is a hardware prototyping agency and venture studio focussing on sustainability tech, based in London, UK.
Find out more at [hard-stuff.com](hard-stuff.com).

This library is written and provided open-source in the hope that you go on to build great things.
