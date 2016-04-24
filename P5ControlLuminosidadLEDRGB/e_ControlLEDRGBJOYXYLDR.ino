/*
 Controla la lumninosidad LED RG con Joystick eje x y
 y la luminosidad del LED azul con LDR
 Kiwibot- Jose Pujol
 */

// declaramos los pines
const int ldrPin = A0; // selecciona el pin de entrada para el joystick x
const int joyXPin = A4; // selecciona el pin de entrada para el joystick x
const int joyYPin = A5; // selecciona el pin de entrada para el joystick x
const int ledRPin = 6;  // selecciona pin 6 para el LED rojo
const int ledGPin = 9;  // selecciona pin 9 para el LED verde
const int ledBPin = 5;  // selecciona pin 9 para el LED verde

// variables que almacenan los datos
int joyXValue = 0; // variable para almacenar los valores del joystick x
int joyXMapvalue = 0; // variable que almacena el valor del sensor mapeado 0-255
int joyYValue = 0; // variable para almacenar los valores del joystick y
int joyYMapvalue = 0; // variable que almacena el valor del sensor mapeado 0-255
int ldrValue = 0; // variable para almacenar los valores de la ldr
int ldrMapvalue = 0; // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  // nada que declarar en el setup
}

void loop() {
  // lee los valores de los sensores
  ldrValue = analogRead(joyYPin);
  joyXValue = analogRead(joyXPin);
  joyYValue = analogRead(joyYPin);
  // mapeamos el valor de los sensores
  joyXMapvalue = map(joyXValue, 0, 1023, 0, 255);
  joyYMapvalue = map(joyYValue, 0, 1023, 0, 255);
  ldrMapvalue = map(ldrValue, 0, 1023, 0, 255);
  // escribimos el valor en analogico
  analogWrite(ledRPin, joyXMapvalue);
  analogWrite(ledGPin, joyYMapvalue);
  analogWrite(ledBPin, ldrMapvalue);
}

