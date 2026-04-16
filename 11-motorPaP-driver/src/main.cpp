#include <Arduino.h>

int pasos[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int pines[4] = {32, 33, 26, 27};
int motorSpeed = 800;
int count = 0;
int nroPasos = 512;

void setup() {
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
}

void loop() {
  if (count < nroPasos){
    for (int j = 0; j < 8; j++){
      for (int i = 0; i < 4; i++) {
        digitalWrite(pines[i], pasos[j][i]);
      }
      delayMicroseconds(motorSpeed);
    }
    count++;
    if (count == nroPasos){
      count = 0;
    }
  }
}
