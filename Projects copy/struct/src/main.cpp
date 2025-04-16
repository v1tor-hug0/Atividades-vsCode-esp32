#include <Arduino.h>

struct Pessoa
{
  char nome[20];
  int idade;
  float altura;
  bool calvice;
};

Pessoa aluno;
Pessoa professor;


struct RGB
{
  int r;
  int g;
  int b;
};

RGB roxo;
RGB ciano;
RGB rosa;
RGB verde;


void setup() 
{
  Serial.begin(9600);

/*strcpy(aluno.nome, "Vitor");
aluno.idade = 17;
aluno.altura = 1.73;
aluno.calvice = false;

strcpy(professor.nome, "Ordilei");
professor.idade = 47;
professor.altura = 1.80;
professor.calvice = true;

Serial.printf("Meu nome e: %s\n\r", aluno.nome);
Serial.printf("E tenho %d anos\n\r", aluno.idade);
Serial.printf("Tenho %.2f metros\n\r", aluno.altura);
Serial.printf("E %s calvo", aluno.calvice ? "sou " : "nao sou");


Serial.printf("Meu nome e: %s\n\r", professor.nome);
Serial.printf("E tenho %d anos\n\r", professor.idade);
Serial.printf("Tenho %.2f metros\n\r", professor.altura);
Serial.printf("E %s calvo\n\r", professor.calvice ? "sou " : "nao sou"); */ 



  roxo.r = 125;
  roxo.g = 0;
  roxo.b = 180;


  ciano.r = 45;
  ciano.g = 125;
  ciano.b = 140;


  rosa.r = 195;
  rosa.g = 45;
  rosa.b = 140;


  verde.r = 0;
  verde.g = 255;
  verde.b = 0;

  Serial.printf("Roxo RGB: %d, %d, %d\n\r", roxo.r, roxo.g, roxo.b);
  Serial.printf("Ciano RGB: %d, %d, %d\n\r", ciano.r, ciano.g, ciano.b);
  Serial.printf("Rosa RGB: %d, %d, %d\n\r", rosa.r, rosa.g, rosa.b);
  Serial.printf("Verde RGB: %d, %d, %d\n\r", verde.r, verde.g, verde.b);

}

void loop() 
{

}

