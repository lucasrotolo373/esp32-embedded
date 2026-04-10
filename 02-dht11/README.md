# ESP32 DHT11 Temperature & Humidity Sensor

Second project in my ESP32 embedded systems portfolio.

## What it does
Reads temperature and humidity from a DHT11 sensor every 2 seconds
using non-blocking timing with millis().

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- DHT11 temperature and humidity sensor
- 10kΩ pull-up resistor between VCC and DATA

## Wiring
| DHT11 | ESP32 |
|-------|-------|
| VCC   | 3.3V  |
| DATA  | GPIO4 |
| GND   | GND   |

## Known issue
Sensor returns NaN readings — likely damaged due to incorrect wiring
during initial setup (pins connected in wrong order). The code is
correct and has been verified. A replacement DHT11 is needed to
confirm full functionality.

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `02-dht11` folder

## Serial output
Open monitor at 115200 baud.
Expected output: `TEMPERATURA: 24.00 | HUMEDAD: 60.00`
