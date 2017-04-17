/*
 * Inicio de un juego con la matriz de LEDS
 */

#include <Matriz.h>
Matriz matriz = Matriz(6, 9, 5);

// Variable para almacenar número aleatorio
int randNumber = 0;

// Variable para almacenar serie
int serie [10];

// Variables de tiempo
long tiempoActual = 0;
long tiempoAnterior = 0;
long intervalo=2000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiempoActual=millis();
  if (tiempoActual - tiempoAnterior > intervalo) {
    tiempoAnterior=tiempoActual;
    matriz.cleanMatrix();
    randomSeed(analogRead(A0));
    randNumber = random(1, 5);
    Serial.print(randNumber);  
  }
  matriz.printNumber(randNumber);
}

