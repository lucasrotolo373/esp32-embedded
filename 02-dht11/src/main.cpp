#include <Arduino.h>
#include <DHT.h>

#define DATA_PIN 4
#define DHT_TYPE DHT11

uint64_t last = 0;
DHT dht(DATA_PIN, DHT_TYPE);

void setup() {
    Serial.begin(115200);
    delay(2000);
    dht.begin();
}

void loop() {
  if ((millis() - last) >= 2000) {
      Serial.print("TEMPERATURA: ");
      Serial.println(dht.readTemperature());
      Serial.print("HUMEDAD: ");
      Serial.println(dht.readHumidity());
      last = millis();
    }
}
