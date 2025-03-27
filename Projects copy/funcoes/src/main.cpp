#include <Arduino.h>

#define led 18

//* prototipo da funcao
void ligaLed (uint8_t);
void desligaLed (uint8_t );

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  ligaLed(led);
  delay(300);
  desligaLed(led);
  delay(300);
}

void ligaLed (uint8_t pin)
{
  digitalWrite(pin, HIGH);
}

void desligaLed (uint8_t pin)
{
  digitalWrite(pin, LOW);
}