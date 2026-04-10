#include <Arduino.h>

#define LED_PIN 2
#define DATA_PIN 34
bool ledState = false;
int count = 0;
float suma = 0.0;
float temperatura = 0.0;
int heartbeatCount = 0;
SemaphoreHandle_t xMutex;

void blinkLed(void *pvParameters){
  while(1){
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    xSemaphoreTake(xMutex, portMAX_DELAY);
    Serial.print("LED: ");
    Serial.print(ledState ? "ON" : "OFF");
    Serial.print(" | time: ");
    Serial.print(millis());
    Serial.println("ms");
    xSemaphoreGive(xMutex);
    vTaskDelay(pdMS_TO_TICKS(500)); 
  }
}

void lm35(void *pvParameters){
  while(1){
    float voltaje_mv = (analogRead(DATA_PIN) * 3300.0) / 4095.0;
    temperatura = voltaje_mv / 10;
    count++;
    suma = suma + temperatura;
    if (count == 10){
      float promedio = suma / 10;
      xSemaphoreTake(xMutex, portMAX_DELAY);
      Serial.print("TEMPERATURA: ");
      Serial.println(promedio);
      xSemaphoreGive(xMutex);
      suma = 0.0;
      count = 0;
    }
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void pulse(void *pvParameters){
  while(1){
    xSemaphoreTake(xMutex, portMAX_DELAY);
    Serial.print("HEARTBEAT: ");
    Serial.print(heartbeatCount);
    xSemaphoreGive(xMutex);
    heartbeatCount++;
    vTaskDelay(pdMS_TO_TICKS(1000)); 
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  xMutex = xSemaphoreCreateMutex();
  xTaskCreate(blinkLed, "Tarea:1", 2048, NULL, 1, NULL);
  xTaskCreate(lm35, "Tarea:2", 2048, NULL, 1, NULL);
  xTaskCreate(pulse, "Tarea:3", 2048, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
}
