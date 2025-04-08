#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define canalA 19
#define canalB 18
#define botao 23

Bounce botaoEncoder = Bounce();

int encoderUpdate(void);

const int8_t tabelaTrancicao[4][4] = {
/*  +1 Horario
     0 parado
    -1 antihorario
*/

      /*  0    1   2   3    */
/*0*/    { 0, -1,  1,  0},
/*1*/    { 1,  0,  0, -1},
/*2*/    {-1,  0,  0,  1},
/*3*/    { 0,  1, -1,  0}
    };

//* 10231023 HORARIO
//* 32013201 ANTIHORARIO

void
setup()
{
  pinMode(canalA, INPUT);
  pinMode(canalB, INPUT);
  botaoEncoder.attach(botao, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int dirEncoder = encoderUpdate();
  botaoEncoder.update();

  static bool posicaoMenu = 1; //*0-Intensidade do led   1-Menu
  static int posicaoSeta = 0;
  
  static int brilhoLedA;
  static int brilhoLedB;
  static int brilhoLedC;
  static int brilhoLedD;
     


  unsigned long tempoAtual = millis();
  static unsigned long tempoAnterior = 0;

 if(botaoEncoder.fell())
 {
    posicaoMenu = !posicaoMenu;
 }

 if (posicaoMenu)  //Mudando as setas
 {
   if (dirEncoder != 0)
   {
     posicaoSeta += dirEncoder;
     if (posicaoSeta > 3)
       posicaoSeta = 0;
     else if (posicaoSeta < 0)
       posicaoSeta = 3;
    
    Serial.println(posicaoSeta);
   }
 } 
 else // Mudando intensidade de um led
 {
  switch (posicaoSeta)
  {
    if (dirEncoder != 0)
    {
    case 0:

      brilhoLedA += dirEncoder * 10;
      if (brilhoLedA > 100)
        brilhoLedA = 100;
      else if (brilhoLedA < 0)
        brilhoLedA = 0;

      break;

    case 1:

      brilhoLedB = constrain(brilhoLedB, 0, 100);
      brilhoLedB += dirEncoder * 10;

      break;

    case 2:

      brilhoLedC = constrain(brilhoLedC, 0, 100);
      brilhoLedC += dirEncoder * 10;

      break;

    case 3:

      brilhoLedD = constrain(brilhoLedD, 0, 100);
      brilhoLedD += dirEncoder * 10;

      break;
    }
  }
 }

}






  int encoderUpdate()
  {
  bool leituraCanalA = digitalRead(canalA);
  bool leituraCanalB = digitalRead(canalB);
  int estadoAtual = ((leituraCanalA << 1) | leituraCanalB);
  static int estadoAnterior = 3;

  int estado = 0;
  int acumulador = 0;
 

  if (estadoAtual != estadoAnterior)
  {
    acumulador += tabelaTrancicao[estadoAnterior][estadoAtual];
      if(estadoAtual == 3)
      {
        if(acumulador == 4)
        estado = 1;
          else if(acumulador == -4)
            estado = -1;

        acumulador = 0;
        Serial.println(estado);
      }
      return estado;
  }
  }