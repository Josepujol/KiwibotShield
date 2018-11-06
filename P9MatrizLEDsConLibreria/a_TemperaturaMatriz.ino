/*
  Temperatura Matriz LEDs
  Usando LM35 como sensor temperatura
  Jose Pujol- kiwibot
  Abril de 2016
 */

#include <Matriz.h>
Matriz matriz(6, 9, 5);

const int tempPin = A1;
float lectura=0;
float tempValue = 0;

void setup() {
  // nada que declarare en el setup
}

void loop() {

  //lectura de la temperatura
  lectura = analogRead(tempPin);
  //formula de la temperatura para sensor LM35
  tempValue = (lectura * 5.0 * 100.0) / 1024.0;
  // representa el numero en la matriz
  matriz.printNumber(tempValue);

}
