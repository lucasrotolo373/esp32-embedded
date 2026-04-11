# ESP32 RFID Reader - MFRC522

Sixth project in my ESP32 embedded systems portfolio.

## What it does
Reads the UID of RFID cards and key fobs using the MFRC522 module
over SPI protocol. Designed as the foundation for an access control system.

## Protocol: SPI
The MFRC522 communicates via SPI (Serial Peripheral Interface).
SPI uses a shared clock between master and slave, allowing high-speed
communication. The SS (Slave Select) pin activates the specific device
on the shared bus.

## How RFID works
The MFRC522 generates a 13.56MHz electromagnetic field. When a passive
card approaches, its internal coil harvests energy from the field via
electromagnetic induction — no battery required. The card uses that
energy to transmit its unique UID back to the reader.

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- MFRC522 RFID module
- RFID card and key fob

## Wiring
| MFRC522 | ESP32   |
|---------|---------|
| SDA(SS) | GPIO21  |
| SCK     | GPIO18  |
| MOSI    | GPIO23  |
| MISO    | GPIO19  |
| GND     | GND     |
| RST     | GPIO22  |
| 3.3V    | 3.3V    |

## Known issue
Module pins were not pre-soldered. SPI communication returns 0xFF
(no response), indicating the bus is not functional due to poor
pin contact. Soldering required to complete this project.

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `06-rfid` folder
