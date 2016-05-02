/*
  Temperatura Matriz LEDs
  Usando LM35 como sensor temperatura
  Jose Pujol- kiwibot
  Abril de 2016
 */

#include <Matriz.h>
Matriz matriz(6, 9, 5);

const int tempPin = A1;
int tempValue = 0;

void setup() {
  // nada que declarare en el setup
}

void loop() {

  //lectura de la temperatura
  tempValue = analogRead(tempPin);
  //formula de la temperatura para sensor LM35
  tempValue = (tempValue * 5 * 100) / 1024;
  // representa el numero en la matriz
  matriz.printNumber(tempValue);

}
