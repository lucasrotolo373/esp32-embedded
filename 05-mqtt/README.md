# ESP32 MQTT WiFi Temperature Publisher

Fifth project in my ESP32 embedded systems portfolio.

## What it does
Reads temperature from an LM35 analog sensor and publishes the data
every 5 seconds to an MQTT broker over WiFi. Data can be received
by any MQTT client subscribed to the topic from anywhere in the world.

## Stack
- **Transport**: WiFi 2.4GHz
- **Protocol**: MQTT over TCP (port 1883)
- **Broker**: test.mosquitto.org (public broker)
- **Topic**: `lucasrotolo/temperatura`
- **Sensor**: LM35DZ analog temperature sensor

## Key concepts demonstrated

### WiFi connection
ESP32 connects to a 2.4GHz network using the WiFi library.
The ESP32 only supports 2.4GHz — not 5GHz.

### MQTT pub/sub model
Unlike HTTP request/response, MQTT uses a publish/subscribe model.
The ESP32 publishes to a topic and any subscriber receives the data
automatically through the broker. No polling required.

### Why MQTT over HTTP for IoT
- Minimal 2-byte header vs hundreds of bytes in HTTP
- Broker as intermediary simplifies architecture with many devices
- Configurable QoS levels for delivery guarantees
- Low latency and low power consumption

### Float to string conversion
MQTT payload must be a char* so float temperature is converted
using dtostrf(value, width, decimals, buffer).

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- LM35DZ temperature sensor

## Wiring
| LM35   | ESP32  |
|--------|--------|
| VCC    | 3.3V   |
| OUTPUT | GPIO34 |
| GND    | GND    |

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Update ssid and password in main.cpp
4. Run `pio run --target upload` inside the `05-mqtt` folder


## Monitor output
Conectando al WiFi......
Conectado!
Conectado al broker MQTT!
Mensaje publicado!
Mensaje publicado!
