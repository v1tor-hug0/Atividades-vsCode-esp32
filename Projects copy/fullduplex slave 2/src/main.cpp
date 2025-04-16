#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;


void setup() {
  Serial.begin(9600);
  if(!SerialBT.begin("SLAVEVITOR", false))
  {
    Serial.println("Erro");
  }

}

void loop() 
{
 if(Serial.available())
 {
  String comandoEnviar = Serial.readStringUntil('\n');
  comandoEnviar.trim();
  SerialBT.println(comandoEnviar);
 }

 if(SerialBT.available())
 {
  String comandoReceber = Serial.readStringUntil('\n');
  comandoReceber.trim();
  Serial.printf("Comando recebido: %s\n\r", comandoReceber);
  if(comandoReceber.equals("liga"))
    {

    } else if(comandoReceber.equals("desliga"))
    {

    } else if(comandoReceber.equals("pisca"))
    {

    } else 
    {
      Serial.println("Comando nao reconhecido");
    }

 
}
}
