#include <Arduino.h>

#define DATA_PIN 34

uint64_t last = 0;
int count = 0;
float suma = 0.0;
float temperatura = 0.0;

void setup() {
    Serial.begin(115200);
    delay(2000);
}

void loop() {
  if ((millis() - last) >= 2000) {
      float voltaje_mv = (analogRead(DATA_PIN) * 3300.0) / 4095.0;
      temperatura = voltaje_mv / 10;
      count++;
      suma = suma + temperatura;
      last = millis();
  }
  if (count == 10){
      float promedio = suma / 10;
      Serial.print("TEMPERATURA: ");
      Serial.println(promedio);
      suma = 0.0;
      count = 0;
  }
}