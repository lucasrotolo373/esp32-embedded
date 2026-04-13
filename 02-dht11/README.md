# ESP32 DHT11 Temperature & Humidity Sensor

Second project in my ESP32 embedded systems portfolio.

## What it does
Reads temperature and humidity from a DHT11 sensor every 2 seconds
using non-blocking timing with millis().

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- DHT11 temperature and humidity sensor

## Wiring
| DHT11 | ESP32 |
|-------|-------|
| DATA  | GPIO27|
| VCC   | 3.3V  |
| GND   | GND   |


## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `02-dht11` folder

## Serial output
Open monitor at 115200 baud.
Expected output: `TEMPERATURA: 24.00 | HUMEDAD: 60.00`
