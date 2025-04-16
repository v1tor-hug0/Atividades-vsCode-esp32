#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
#define led 2

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  if(!SerialBT.begin("ESPVITORMASTER", true))
  {
    Serial.println("Erro");
  }
  if(SerialBT.connect("SlaveThur"))
  {
    Serial.println("Conectado");
  } else {
    Serial.println("Nao conectado");
  }
}

void loop() 
{
  static bool estadoLed = 0;
  static bool piscaLed = 0;

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
    Serial.printf("Comando recebido: %s \n\r", comandoReceber);
    if (comandoReceber.equals("LIGA"))
    {
      estadoLed = 1;
      piscaLed = 0;
    }
    else if (comandoReceber.equals("DESLIGA"))
    {
      estadoLed = 0;
      piscaLed = 0;
    }
    else if (comandoReceber.equals("PISCA"))
    {
      piscaLed = 1;
    }
    else
    {
      Serial.println("Comando nao reconhecido");
    }

    
  }

  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;

  if (piscaLed)
  {
    if (tempoAtual - tempoInicial > 300)
    {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
  }
  digitalWrite(led, estadoLed);
}

