#include <Arduino.h>

#define LED_PIN 2  // Pin del LED interno del ESP32
uint64_t last = 0;
bool ledState = false;

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);  // Configuramos el pin como salida
}

void loop() {
    if ((millis() - last) >= 1000) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      Serial.print("LED: ");
      Serial.print(ledState ? "ON" : "OFF");
      Serial.print(" | time: ");
      Serial.print(millis());
      Serial.println("ms");
      last = millis();
    }   
}