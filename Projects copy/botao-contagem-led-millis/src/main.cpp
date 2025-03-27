#include <Arduino.h>

#define led 18
#define botao 23

void setup() {

Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {

  int leituraBotao;
  leituraBotao = digitalRead(botao);
  static int leituraAnterior = 1;

  static bool estadoLed = 0;
 
  static int contagem = 0;

  static unsigned long tempoDeBounce = 0;
  unsigned long tempoAtual = millis();
  const unsigned long tempo = 50;
  static bool acao = 1;


  //* Marca quando uma mudanca acontece 
  if (leituraBotao != leituraAnterior) 
  {
    tempoDeBounce = tempoAtual;
  }

  //* Verifica se a mudanca de estado esta estavel
  if ((tempoAtual - tempoDeBounce) > 50)
  {
    //* Houve uma proposital do estado do botao ?
      if (leituraBotao != acao )
      {
        acao = leituraBotao;
        if (!leituraBotao)
        {
          // Botao foi pressionado
          contagem++;
          estadoLed = !estadoLed;
          digitalWrite(led, estadoLed);
          Serial.println(contagem);
        } 
      }
  }

  leituraAnterior = leituraBotao;

  



/*
if (leituraAnterior && !leituraBotao )
  {
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
    contagem++;
    Serial.println(contagem);
}

leituraAnterior = leituraBotao;
*/
}