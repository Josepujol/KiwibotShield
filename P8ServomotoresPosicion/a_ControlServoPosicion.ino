/*
 Control de un servo mediante un potenciometro
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

// incluye la libreria servo
#include <Servo.h>
// crea el objeto myservo tipo servo
Servo myservo;
// pin para conectar el potenciometro
const int potPin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup()
{
  // sconecta myservo al pin 8
  myservo.attach(8);
}

void loop()
{
  // lectura del potenciometro
  val = analogRead(potPin);
  // mapea el valor a escala 0-180º
  val = map(val, 0, 1023, 0, 180);
  // escribe el angulo en el objeto myservo
  myservo.write(val);
  // tiempo de espera para que el servo alcance la posicion
  delay(15);
}
