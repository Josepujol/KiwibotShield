/*
Impresion Sensor luz en la Matriz LEDs
Usando LED RGB y LDR
 */
 
// incluir la libreria de la matriz de LEDs
#include <Matriz.h>
// pines de conexion de la matriz
Matriz matriz(6, 9, 5);
 // establece el pin de la LDR
const int ldrPin = A0;   

// variable para almacenar el valor del sensor
int ldrValue = 0;
// variable para almacenar el valor del sensor mapeado
int ldrMapvalue=0;

void setup() {
  // nada que declarar en el set up
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);
  // mapeamos el valor del sensor de 0 a 99
  ldrMapvalue= map(ldrValue, 0, 1023, 0, 99);
  // imprimimos el valor en la matriz de leds
  matriz.printNumber(ldrMapvalue);
}


