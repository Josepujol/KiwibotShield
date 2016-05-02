/* Programa que recorre los puntos de la matriz de LEDs
 *  Control de la matriz de LEDS sin librería
 *  Jose Pujol- Kiwibot
 *  Octubre 2015
*/

// variables pines
const int latchPin = 6;    // pin para el latch de los 74CH495
const int datosPin = 5;    // pin para Datos serie del 74CH495
const int relojPin = 9;     // pin para reloj del 74CH495

// variables para los puntos de la matriz
byte columna[7] = {B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
byte fila[5] = {B11110111, B11101111, B11011111, B10111111, B01111111};


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(datosPin, OUTPUT);
  pinMode(relojPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      // Ponemos el latch para escuchar datos
      digitalWrite(latchPin, LOW);
      // mandamos los datos para el segundo registro
      // que esta conectado a las filas
      shiftOut(datosPin, relojPin, LSBFIRST, fila[i]);
      // mandamos los datos para el primer registro
      // que esta conectado a las columnas
      shiftOut(datosPin, relojPin, LSBFIRST, columna[j]);
      // activamos la salida de los datos
      digitalWrite(latchPin, HIGH);
      delay(100);
    }
  }
}
