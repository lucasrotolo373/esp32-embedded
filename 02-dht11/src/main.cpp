#include <Arduino.h>
#include <DHT.h>

#define DATA_PIN 27
#define DHT_TYPE DHT11

uint64_t last = 0;
DHT dht(DATA_PIN, DHT_TYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();
}

void loop() {
  if ((millis() - last) >= 2000) {
    float temperatura = dht.readTemperature();  // Leemos la temperatura
    float humedad = dht.readHumidity();         // Leemos la humedad
    if (isnan(temperatura) || isnan(humedad)) {
        Serial.println("Error al leer el sensor DHT");
        return; 
    }
    Serial.print("TEMPERATURA: ");
    Serial.println(temperatura);
    Serial.print("HUMEDAD: ");
    Serial.println(humedad);
    last = millis();
    }
}
