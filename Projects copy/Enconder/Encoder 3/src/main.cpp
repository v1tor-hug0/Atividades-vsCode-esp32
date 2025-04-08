#include <Arduino.h>

#define canalA 19
#define canalB 18

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
  Serial.begin(9600);
}

void loop()
{
  bool leituraCanalA = digitalRead(canalA);
  bool leituraCanalB = digitalRead(canalB);
  int estadoAtual = ((leituraCanalA << 1) | leituraCanalB);
  static int estadoAnterior = 3;

  static int contador = 0;
  int acumulador = 0;
 

  if (estadoAtual != estadoAnterior)
  {
    acumulador += tabelaTrancicao[estadoAnterior][estadoAtual];
      if(estadoAtual == 3)
      {
        if(acumulador == 4)
        contador++;
          else if(acumulador == -4)
            contador--;

        acumulador = 0;
        Serial.println(contador);
      }
  }
   
  estadoAnterior = estadoAtual;
}
