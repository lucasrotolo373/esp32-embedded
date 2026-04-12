#include <Arduino.h>


void consumirStack(int nivel) {
    char buffer[50];  // consume 50 bytes por llamada
    //Serial.print(" | &buffer: 0x");
    //Serial.println((uint32_t)&buffer, HEX); 
    Serial.print("Nivel: ");
    Serial.print(nivel);
    Serial.print(" | Watermark: ");
    Serial.println(uxTaskGetStackHighWaterMark(NULL));
    vTaskDelay(pdMS_TO_TICKS(500));
    consumirStack(nivel + 1);  
}

void tareaStack(void *pvParameters) {
    consumirStack(0);
}

void setup() {
  Serial.begin(115200);
  xTaskCreate(tareaStack, "Tarea:1", 4096, NULL, 1, NULL);
}

void loop() {
}