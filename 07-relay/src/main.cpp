#include <Arduino.h>

#define PIN_POT 34 
#define PIN_RELAY 26

const int umbral = 2000;
uint64_t last = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_RELAY, LOW); 
}

void loop() {
  if (millis() - last > 1000){
    int valorPot = analogRead(PIN_POT);
    Serial.print("Lectura del potenciómetro: ");
    Serial.println(valorPot);
    if (valorPot > umbral+100) {
      digitalWrite(PIN_RELAY, HIGH); 
      Serial.println(" -> ¡Relay ACTIVADO!");
    } else if(valorPot < 1900){
        digitalWrite(PIN_RELAY, LOW);  
    }
    last = millis();
  }
}