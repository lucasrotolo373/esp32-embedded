# Ejercicio 11 — Motor paso a paso 28BYJ-48 con ULN2003

## Consigna
Controlar un motor paso a paso 28BYJ-48 con driver ULN2003 sin librerías externas.

## Descripción
Se implementa la secuencia de medio paso (8 pasos) manualmente con un array 2D.
El motor realiza 512 ciclos completos para completar una vuelta de 360°.

## Conexiones
- IN1 → GPIO 32
- IN2 → GPIO 33
- IN3 → GPIO 26
- IN4 → GPIO 27
- ULN2003 VCC → 5V (VIN)
- ULN2003 GND → GND

## Conceptos clave
- Medio paso: secuencia de 8 filas que activa las bobinas de a una y de a dos
- El for interno recorre los 4 pines de una fila → 1 paso completo
- El for externo recorre las 8 filas → 1 ciclo completo de la secuencia
- delayMicroseconds() entre pasos controla la velocidad
- 512 ciclos = 1 vuelta completa (360°)
