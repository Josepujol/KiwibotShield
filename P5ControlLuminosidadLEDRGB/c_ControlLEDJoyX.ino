/*
 Controla la lumninosidad LED rojo con Joystick eje x
 Kiwibot- Jose Pujol
 */

// declaramos los pines
const int joyXPin = A4; // selecciona el pin de entrada para el joystick x
const int ledRPin = 6;  // selecciona pin 6 para el LED rojo

// variables que almacenan los datos
int joyXValue = 0; // variable para almacenar los valores del joystick x
int joyXMapvalue = 0; // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  // nada que declarar en el setup
}

void loop() {
  // lee el valor del sensor
  joyXValue = analogRead(joyXPin);
  // mapea el valor a escala 0-255
  joyXMapvalue = map(joyXValue, 0, 1023, 0, 255);

  // escribimos el valor en analogico en el LED
  analogWrite(ledRPin, joyXMapvalue);
}
