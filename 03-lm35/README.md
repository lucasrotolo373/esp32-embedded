# ESP32 LM35 Analog Temperature Sensor

Third project in my ESP32 embedded systems portfolio.

## What it does
Reads temperature from an LM35 analog sensor using the ESP32's built-in
ADC. Averages 10 readings to reduce noise before displaying the result.

## How it works
The LM35 outputs 10mV per degree Celsius. The ESP32 ADC converts the
voltage to a 12-bit value (0-4095) representing 0-3300mV.

voltage_mv = (analogRead(pin) * 3300.0) / 4095.0
temperature = voltage_mv / 10.0

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- LM35DZ temperature sensor

## Wiring
| LM35   | ESP32  |
|--------|--------|
| VCC    | 3.3V   |
| OUTPUT | GPIO34 |
| GND    | GND    |

## Known issue
ADC readings are noisy due to poor breadboard contact. Averaging 10
readings partially mitigates this.

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `03-lm35` folder
