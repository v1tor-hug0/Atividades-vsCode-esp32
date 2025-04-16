#include <Arduino.h>
#include "BluetoothSerial.h"

#define led 2

BluetoothSerial SerialBT;

String palavra = "";


void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP-VITOR-HUGO");
  SerialBT.println("algo");
  pinMode(led, OUTPUT);
}

void loop() 
{
  SerialBT.println("SLV");
  delay(1000);

  while(SerialBT.available())
  {
    char caractere = SerialBT.read();

    if(caractere == '\n'|| caractere == '\r')
    {
      //SerialBT.println(palavra);
      if(palavra.equalsIgnoreCase("liga"))
      {
        digitalWrite(led, HIGH);
        SerialBT.println("Led ligado");
      } 
      else if(palavra.equals("desliga"))
      {
        digitalWrite(led, LOW);
        SerialBT.println("Led desligado");
      }
      else 
      {
        SerialBT.println("Comando nao reconhecido");
      }
      if (caractere == '\r')
      {
        palavra = "";
      }
    }
    
    
      palavra += caractere;

    /*if (caractere == 'L')
    {
      digitalWrite(led, HIGH);
      Serial.println("Led ligado");
    }
    else if (caractere == 'D')
    {
      digitalWrite(led, LOW);
      Serial.println("Led desligado");
    }
    else 
    {
      Serial.println("Digite apenas L ou D");
    }

    Serial.printf("Voce digitou %c \n\r", caractere);*/
  }

  
}
