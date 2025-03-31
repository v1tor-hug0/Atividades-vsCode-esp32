#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define led_ama 4
#define led_verm 18
#define botao 23

// *** instacia de Objetos ***
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  randomSeed(analogRead(36));
  pinMode(led_ama, OUTPUT);
  pinMode(led_verm, OUTPUT);
  pinMode(botao, INPUT_PULLUP);

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("LIGAR DETECTOR ");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("PRESSIONE O BOTAO");
}

void loop()
{
  if (digitalRead(botao) == LOW)

  {
    lcd.clear();
    lcd.print("ANALISANDO...");
    digitalWrite(led_ama, LOW);
    digitalWrite(led_verm, LOW);

    for (int i = 0; i < 5; i++)
    {
      digitalWrite(led_ama, HIGH);
      digitalWrite(led_verm, HIGH);
      delay(500);
      digitalWrite(led_ama, LOW);
      digitalWrite(led_verm, LOW);
      delay(500);
    }
    int resultado = random(5);
    
    switch (resultado)
    {
    case 0:
      lcd.setCursor(0,0);
      lcd.print("100% VERDADE     ");
      digitalWrite(led_ama, HIGH);
      break;

    case 1:
      lcd.setCursor(0,0);
      lcd.print("MENTIRA DESCARADA");
      digitalWrite(led_verm, HIGH);
      break;

    case 2:
      lcd.setCursor(0,0);
      lcd.print("MEIA VERDADE      ");
      digitalWrite(led_verm, HIGH);
      digitalWrite(led_ama, HIGH);
    break;

    case 3:
      lcd.setCursor(0,0);
      lcd.print("NIVEL DE MENTIRA:  ");
      lcd.setCursor(0,1);
      lcd.print("MAIS DE 8000");
      digitalWrite(led_verm, HIGH);
    
    case 4:
      lcd.setCursor(0,0);
      lcd.print("ERRO DE LEITURA   ");
      lcd.setCursor(0,1);
      lcd.print("FACA DENOVO  ");
      digitalWrite(led_verm, HIGH);
    break;
    }
    
    
    delay(3000);
    digitalWrite(led_verm, LOW);
    digitalWrite(led_ama, LOW);
    lcd.setCursor(0,0);
    lcd.print("PRESSIONE O BOTAO");
    lcd.setCursor(0,1);
    lcd.print("             ");
  }
}