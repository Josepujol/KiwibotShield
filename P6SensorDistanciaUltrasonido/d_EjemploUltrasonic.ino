/*
Ejemplo de medicion de distancia usando librería ultrasonic

*/

// incluye la libreria ultrasonic
#include <Ultrasonic.h>

// Declara objeto ultrasonic
// Pin 11 Trigger, PIN 12 Echo
Ultrasonic ultrasonic(11,12); 

void setup() {
  // abre puerto serie
  Serial.begin(9600); 
}

void loop()
{
  // imprime el valor de distancia en cm
  Serial.print(ultrasonic.Ranging(CM)); 
  Serial.println(" cm" );
  delay(100);
}
