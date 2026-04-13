# ESP32 Hardware Interrupts with Debouncing

Ninth project in my ESP32 embedded systems portfolio.

## What it does
Counts button presses using hardware interrupts and toggles the onboard
LED on each press. Implements software debouncing to filter mechanical
bounce noise.

## Key concepts demonstrated

### Hardware Interrupts
An interrupt is an asynchronous hardware signal that stops normal execution
to handle an event. Unlike syscalls (synchronous), interrupts occur at any
moment regardless of what the CPU was doing.

Flow: hardware signal -> CPU finishes current instruction -> saves context
-> jumps to ISR -> executes ISR -> restores context -> continues.

### ISR (Interrupt Service Routine)
The function that handles the interrupt. Must be placed in internal RAM
using IRAM_ATTR for instant execution (no Flash read latency).
Rules: keep it extremely short, never call Serial or delay, only modify
volatile variables.

### volatile keyword
Tells the compiler never to cache a variable in a register — always read
from RAM. Required for variables shared between ISR and main code.
Without volatile, the compiler may optimize away reads and the main loop
never sees the updated value.

### INPUT_PULLUP
Connects an internal resistor between the pin and 3.3V. Prevents the pin
from floating (reading random noise) when nothing is connected.
With pull-up: unpressed = HIGH, pressed = LOW -> use FALLING mode.

### Debouncing
Mechanical buttons don't make a clean transition. They vibrate for
milliseconds generating dozens of FALLING edges before stabilizing.
Solution: ignore edges for 200ms after the first one.

### FALLING vs RISING
With INPUT_PULLUP the pin is HIGH when unpressed and falls to LOW when
pressed. FALLING triggers on that transition. RISING would trigger on
release instead of press.

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- Push button
- GPIO32 with INPUT_PULLUP

## Wiring
| Component | Pin | ESP32  |
|-----------|-----|--------|
| Button    | A   | GPIO32 |
| Button    | B   | GND    |

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `09-interrupts` folder
