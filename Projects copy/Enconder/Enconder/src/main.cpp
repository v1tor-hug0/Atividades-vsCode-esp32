#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define sw 23
#define dt 19
#define clk 18

void setup()
{
  pinMode(sw, INPUT);
  pinMode(dt, INPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop()
{
  int estadoAtual = (digitalRead(dt) << 1 | digitalRead(clk));
  static int estadoAnterior = 0;
  static bool anteriorS1 = 0;
  static bool anteriorS2 = 0;
  bool atualS1 = digitalRead(dt);
  bool atualS2 = digitalRead(clk);
  char posicao = 0;

  static int cont = 0;

  if (atualS1 != anteriorS1 || atualS2 != anteriorS2)
  {
    anteriorS1 = atualS1;
    anteriorS2 = atualS2;

    Serial.print(digitalRead(dt));
    Serial.print(" ");
    Serial.println(digitalRead(clk));

    if (atualS1 && atualS2)
    {
      Serial.println("----------");
    }
  }

 


  if (estadoAnterior == 2 && !estadoAtual)
  {
    posicao = 1;
  }

  if (estadoAnterior && !estadoAtual)
  {
    posicao = 0;
  }

  if (posicao)
  {
    cont++;
    Serial.println(cont);
  }
  else
  {
    cont--;
    Serial.println(cont);
  }
  estadoAnterior = estadoAtual;
}

/*if ()
{
 cont++;
 Serial.println(cont);
}
else
{
 cont--;
 Serial.println(cont);
}

atualS1 = anteriorS1;
atualS2 = anteriorS2;
}*/
