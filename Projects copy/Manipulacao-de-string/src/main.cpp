#include <Arduino.h>

char nome [20];
char nome2[20];

void setup() {
  Serial.begin(9600);

  // Atribui uma string a uma cadeia de caracteres 
  strcpy(nome, "Vitor"); 
  Serial.println(nome);

// Concatena (adiciona) strings a um vetor
  strcat(nome, " Hugo"); 
  Serial.println(nome);

//Tamanho de uso da string
  int tamanho = strlen(nome); 
  Serial.println(tamanho);

  strcpy(nome2, "Vitor a");

//Compara duas strings e retorna 0 se forem iguais
  if(strcmp(nome2, nome) == 0) Serial.println("sao iguais"); 
  else Serial.println("sao diferentes");

  if(strcmp("Vitor Hugo", nome) == 0) Serial.println("sao iguais");
  else Serial.println("sao diferentes");

  //Compara se os 5 primeiros digitos sao iguais
  if(strncmp(nome2, nome, 5) == 0) Serial.println("sao iguais");
  else Serial.println("O comeco nao e igual");

  char buffer[50];
  int temperatura = 25;
  sprintf(buffer, "Temperatura: %d°C", temperatura);
  Serial.println(buffer);
  

}

void loop() {

}

