#include <Arduino.h>
#include "BluetoothSerial.h"

#define led 2

BluetoothSerial SerialBT;



//Esp master
void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESPMASTERVITOR", true); 
  pinMode(led, OUTPUT);

  if(SerialBT.connect("ESP Pa e Pum"))
  {
    Serial.println("conectado");
  } else
  {
    Serial.println("desconectado");
    while(true);
  }
}

void loop() 
{
  SerialBT.print("ping");
  Serial.println("mensagem enviada");

  unsigned long timeout = millis() + 3000;
  while(millis() < timeout)
  {
    if(SerialBT.available())
    {
      String resposta = SerialBT.readStringUntil('\r');
      Serial.printf("Resposta: %s", resposta);
      break;
    }
  }

  

   /* while(SerialBT.available())
  {
    String palavra = SerialBT.readStringUntil('\r');

   // if(caractere == '\n'|| caractere == '\r')
    //{
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
      
        palavra = "";
     
    //}
}*/
}

