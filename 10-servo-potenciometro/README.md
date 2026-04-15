# Ejercicio 10 — Control de servo con potenciómetro

## Consigna
Controlar un servo SG90 con un potenciómetro usando la librería ESP32Servo.

## Descripción
El potenciómetro conectado al pin 32 genera un valor analógico de 0 a 4095 (ADC 12 bits).
Ese valor se mapea al rango del servo (0° a 179°) y se escribe al pin 23.

## Conexiones
- Potenciómetro: VCC a 3.3V, GND a GND, señal a pin 32
- Servo SG90: VCC a VIN (5V), GND a GND, señal a pin 23

## Conceptos clave
- analogRead() en ESP32 devuelve valores de 0 a 4095 (12 bits)
- map() interpola linealmente entre dos rangos
- ESP32Servo maneja la señal PWM del servo automáticamente
- Alimentar el servo desde VIN (5V USB) y no desde 3.3V
