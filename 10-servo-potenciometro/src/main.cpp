#include <Arduino.h>
#include <ESP32Servo.h>

Servo miServo;

#define potenciometro 32
#define pin_servo 23
int i;

void setup(){
	Serial.begin(115200);
	miServo.attach(pin_servo);
}

void loop(){
	i = analogRead(potenciometro);
	i = map(i, 0, 4095, 0, 179);
	Serial.println(i);
	miServo.write(i);
	delay(10);
}
