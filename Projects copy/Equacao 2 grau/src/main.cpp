#include <Arduino.h>
#include <math.h>

int calculoSegGrau(int, int, int);

void setup()
{
  Serial.begin(9600);
  int raizfunction = calculoSegGrau(1, 6, 9);
  Serial.println(raizfunction);
}

void loop()
{
}

int calculoSegGrau(int a, int b, int c)
{
  int resultado;
  int delta;
  delta = sqrt((b * b) - (4 * a * c));

  resultado = (-b + delta) / (2 * a);

  return resultado;
}
