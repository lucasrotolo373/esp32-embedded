# ESP32 Relay Control with Potentiometer

Seventh project in my ESP32 embedded systems portfolio.

## What it does
Controls a relay module using a potentiometer as analog input.
Simulates a real-world scenario where a sensor reading triggers
an actuator — for example, activating a fan or alarm based on temperature.

## Key concepts demonstrated

### Hysteresis
The relay activates above 2100 (ADC value) and deactivates below 1900.
The intermediate range (1900-2100) does nothing, maintaining the current
relay state. This prevents rapid on/off switching when the input is near
the threshold — a fundamental technique in control systems.

### Relay internals
A relay has two electrically isolated circuits:
- **Control circuit**: low voltage (3.3V) from the ESP32 drives an internal coil
- **Load circuit**: can switch high voltage/current loads (AC/DC)

When the ESP32 sets the pin HIGH, current flows through the coil,
generating an electromagnetic field that physically moves a mechanical
contact, closing the load circuit.

### DAC vs ADC
GPIO26 used for relay control also has DAC2 functionality.
DAC (Digital to Analog Converter) is the inverse of ADC —
it converts a digital value to an analog voltage output.
Not used here, but worth noting.

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- 1-channel relay module
- 10K potentiometer

## Wiring
| Component      | Pin   | ESP32  |
|----------------|-------|--------|
| Potentiometer  | OUT   | GPIO34 |
| Potentiometer  | VCC   | 3.3V   |
| Potentiometer  | GND   | GND    |
| Relay          | IN    | GPIO26 |
| Relay          | VCC   | 3.3V   |
| Relay          | GND   | GND    |

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `07-relay` folder

## Serial output
Open monitor at 115200 baud.
Potentiometer ADC value printed every second.
Relay state changes logged when threshold is crossed.
