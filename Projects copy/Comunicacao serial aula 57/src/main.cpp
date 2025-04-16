#include <Arduino.h>
#define led 2

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.print("Comunicacao \n");
}

void loop()
{

  static bool estadoLed = 0;
  static bool piscaLed = 0;
  static int velocidade = 50;

  if (Serial.available())
  {
    String msg = Serial.readStringUntil('\n');
    String por = Serial.readStringUntil('%');
    msg.trim();
    msg.toLowerCase();

    if (msg.equals("liga"))
    {
      piscaLed = 0;
      estadoLed = 1;
    }
    else if (msg.equals("desliga"))
    {
      estadoLed = 0;
      piscaLed = 0;
    }
    else if (msg.equals("pisca"))
    {
      piscaLed = 1;
    }



    if (msg.equals("aumenta") && piscaLed == 1)
    {
      velocidade += 50;
      if (velocidade > 1000)
      {
        velocidade = 1000;
        Serial.println("Velocidade maxima");
      }
    }
    else if (msg.equals("diminui") && piscaLed == 1)
    {
      velocidade -= 50;
      if (velocidade < 50)
      {
        velocidade = 50;
        Serial.println("velocidade minima");
      }
    }



    if (msg.startsWith("vel = "))
    {
      int tamanho = msg.length();
      String extracao = msg.substring(6, tamanho);
      int valorVelocidade = extracao.toInt();
      if (valorVelocidade >= 0 && valorVelocidade <= 100)
        velocidade = map(valorVelocidade, 0, 100, 1000, 50);
      else
        Serial.println("Entre 0 a 100");
    }

  

  }


  unsigned long tempoAtual = millis();
  static unsigned long tempoInicial = 0;

  if (piscaLed)
  {
    if (tempoAtual - tempoInicial > velocidade)
    {
      estadoLed = !estadoLed;
      tempoInicial = tempoAtual;
    }
  }
  digitalWrite(led, estadoLed);
}
