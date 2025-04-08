#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int CLK = 19;
int DT = 18;
int SW = 23;

// Faça o encoder somar ao ir para o sentido horario e
//  subtrair quando estiver indo para o sentido anti-horário

void setup()
{
    Serial.begin(9600);
    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
}

void loop()
{
    int estadoAtualEncoder;
    static bool posicaoAAnterior;
    static bool posicaoBAnterior;
    bool posicaoA = digitalRead(CLK);
    bool posicaoB = digitalRead(DT);
    static int cont = 0;

    if (!posicaoB && posicaoAAnterior && posicaoBAnterior)
    {
        cont++;
        Serial.println(cont);
    }
    else if (!posicaoA && posicaoAAnterior && posicaoBAnterior)
    {
        cont--;
        Serial.println(cont);
    }
    

    posicaoAAnterior = posicaoA;
    posicaoBAnterior = posicaoB;

    // if (posicaoA != posicaoAAnterior && posicaoBAnterior == posicaoB && proxA){
    //     cont ++;
    //     Serial.println(cont);
    //     proxA == 0;
    //     delay(1000);
    // }

    // if (posicaoB != posicaoBAnterior && posicaoAAnterior == posicaoA && proxA){
    //     cont --;
    //     Serial.println(cont);
    //     proxA == 0;
    //     delay(1000);
    // }


/*if (posicaoA != posicaoAAnterior || posicaoB != posicaoBAnterior)
  {
    posicaoAAnterior = posicaoA;
    posicaoBAnterior = posicaoB;

    Serial.print(digitalRead(DT));
    Serial.print(" ");
    Serial.println(digitalRead(CLK));

    if (posicaoA && posicaoB)
    {
      Serial.println("----------");
    }
  }*/


}