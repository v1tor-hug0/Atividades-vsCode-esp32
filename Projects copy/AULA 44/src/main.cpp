#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define led 2
#define botao 0

//****** Instancia de objetos  *********
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Led OFF");
  
}

void loop() {
static int leituraAnterior;
  int leituraBotao;
  static bool estadoLed = 0;
  leituraBotao = digitalRead(botao);


  if (leituraAnterior == 1 && leituraBotao == 0)
  {
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);

    if (estadoLed) {
      lcd.setCursor(4, 0);
      lcd.print ("ON ");
    } else {

      lcd.setCursor(4, 0);
      lcd.print ("OFF");
    }
  }

  leituraAnterior = leituraBotao;
}

