#include <Arduino.h>
#define led 2
#define botao 0


void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(botao));
  delay(200);

  static int leituraAnterior;
  int leituraBotao;
  static bool estadoLed = 0;
  leituraBotao = digitalRead(botao);


  if (leituraAnterior == 1 && leituraBotao == 0)
  {
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
  }

  leituraAnterior = leituraBotao;
}
