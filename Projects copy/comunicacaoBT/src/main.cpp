#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

//ESP SLAVE
void setup() 
{
  Serial.begin(9600);
  SerialBT.begin("ESPVITOR");

  Serial.println("Esperando uma conexao bluetooth");
}

void loop()
{
  if(SerialBT.available())
  {
    String mensagem = SerialBT.readStringUntil('\r');
    Serial.printf("Mensagem recebida %s\n\r", mensagem);

    if(mensagem.equals("ping"))
    {
      SerialBT.print("pong\n\r");
    }
  }

  
}