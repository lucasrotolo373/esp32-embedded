# ESP32 Non-Blocking LED Blink

First project in my ESP32 embedded systems portfolio.

## What it does
Blinks the onboard LED every 1 second using non-blocking timing.

## Why millis() instead of delay()
`delay()` blocks the entire program while waiting. `millis()` allows
the main loop to keep running freely, making it possible to handle
multiple tasks concurrently — a fundamental requirement in real
embedded systems.

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload`

## Serial output
Open monitor at 115200 baud to see LED state and timestamp.
