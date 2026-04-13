#include <Arduino.h>

#define PULSE_PIN 21
#define LED_PIN 2

volatile int contador = 0;
volatile bool botonPresionado = false;
volatile unsigned long ultimoDebounce = 0;
bool ledState = false;

void IRAM_ATTR ISR() {
    unsigned long ahora = millis();
    if (ahora - ultimoDebounce > 200) {
        botonPresionado = true;
        contador++;
        ultimoDebounce = ahora;
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(PULSE_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(PULSE_PIN), ISR, FALLING);
}

void loop() {
    if (botonPresionado) {
        botonPresionado = false;
        Serial.print("Contador: ");
        Serial.println(contador);
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
    }
}