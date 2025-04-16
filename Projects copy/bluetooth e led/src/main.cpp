#include <Arduino.h>
//#include "BluetoothSerial.h"

#define led1 2
#define led2 3
#define led3 4
#define led4 5

//BluetoothSerial SerialBT;

String leds = "";
int brilho;

void setup() {
  Serial.begin(9600);
  //SerialBT.begin("ESPVitor");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  while (Serial.available())
  {
    char enter = Serial.read();

    if (enter == '\n')
    {
      Serial.println("Qual Led ?");
      leds = Serial.read();
      

      if (leds.equals("1"))
      {
        Serial.println("Qual a itensidade?");
        brilho = Serial.read();
        digitalWrite(led1, brilho);
        Serial.printf("Led:%s brilho:%d", leds, brilho);
      }
      leds = "";
    }
    else if (enter != '\r')
    leds += enter;
  }
}
