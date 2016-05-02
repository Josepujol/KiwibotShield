/*
 * Programa para mover un punto de la Matriz con el Joystick
 * Noviembre de 2015
 * Jose Pujol
 */

// Pines registro de desplazamiento
const int latchPin = 6;
const int datosPin = 5;
const int relojPin = 9;

// Pines Joystick
const int joyX = A4;
const int joyY = A5;

// Lectura del Joystick
int joyXValue = 0;
int joyYValue = 0;

//Vector con las columnas como 1s
byte columna[7] = {B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
// Vector con las filas como ceros
byte fila[5] = {B11110111, B11101111, B11011111, B10111111, B01111111};

// Posición del punto en el vector columna y fila
int j = 0;
int i = 0;

// Velocidad de desplazamiento
int tiempo = 100;

void setup() {
  // Declaramos los pines como salidas
  pinMode(latchPin, OUTPUT);
  pinMode(datosPin, OUTPUT);
  pinMode(relojPin, OUTPUT);
}

void loop() {
  //Lee los valores del joystick
  joyXValue = analogRead(joyX);
  joyYValue = analogRead(joyY);

  //Cambia la columna
  if (joyXValue <= 300) {
    if (j > 0) j--;
  }
  if (joyXValue >= 700) {
    if (j < 6) j++;
  }
  //Cambia la fila
  if (joyYValue <= 300) {
    if (i < 4) i++;
  }

  if (joyYValue >= 700) {
    if (i > 0) i--;
  }

  // Escribe el punto en la matriz
  //Recibe datos
  digitalWrite(latchPin, LOW);
  // activa el punto el punto
  shiftOut(datosPin, relojPin, LSBFIRST, fila[i]);
  shiftOut(datosPin, relojPin, LSBFIRST, columna[j]);
  //Muestra los datos recibidos
  digitalWrite(latchPin, HIGH);
  // tiempo que limita la velocidad de desplazamiento
  delay(tiempo);
}
