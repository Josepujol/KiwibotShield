/* JUEGO MATRIZ DE LEDS
Base para desarrollar un juego con la matriz de LEDS
Pixel movil con el acelerometro
Pixel fijo parpadeante random
El juego consiste en capturar con el pixel movil el pixel fijo
Desarrollado por José Pujol y Alberto Pumar
Febrero de 2015
*/

#include <Matriz.h>   // Incluimos la libreria
Matriz matriz (6, 9, 5);   // pines datos, latch y reloj

// Conexion de pines
const int xaccelPin = A2;  // pin acelerometro x
const int yaccelPin = A3;  // pin acelerometro y
const int zumbadorPin = 10; // pin zumbador

//Valor sensor acelerometro
int xaccelValue = 0;
int yaccelValue = 0;

// Coordenadas pixel movil
int filaMovil = 1;
int columnaMovil = 1;

// Coordenadas pixel fijo parpadeante
int filaFijo = 0;
int columnaFijo = 0;

// variables relacionadas con el tiempo
unsigned long previousMillis = 0;  // vble para tiempo para parpadeo
unsigned long tiempoAnterior = 0; // vble para tiempo para mover pixel
unsigned long currentMillis = 0;  // vble para almacenar tiempo actual
long interval = 500;   // intervalo de parpadeo
int state = 0;    // estado del pixel parpadeante

void setup() {

  pinMode(zumbadorPin, OUTPUT);  // se declara zumbador como salida
  // random para pixel parpadeante
  randomSeed(analogRead(A0));  // semilla para inicializar el random
  filaFijo = random (1, 6);    // valor para fila
  columnaFijo = random (1, 8);    // valor para columna
}

// funcion que enciende los pixeles
void encenderpixels() {
  // si el tiempo transcurrido es mayor que el intervalo
  if (currentMillis - previousMillis >= interval) {
    // actualiza la vble previousMillis
    previousMillis = currentMillis;
    // cambia el estado
    if (state == 0) state = 1;
    else state = 0;
  }
  // Si el estado es cero enciende el pixel fijo y el movil
  if (state == 0) {
    matriz.printPixel(filaMovil, columnaMovil);
    matriz.printPixel(filaFijo, columnaFijo);
  }
  // si el estado es uno apaga el pixel fijo
  else {
    matriz.cleanMatrix();
    matriz.printPixel(filaMovil, columnaMovil);
  }
}
// funcion que mueve el pixel por la matriz de leds
void moverpixel() {
  // lectura del acelerometro
  xaccelValue = analogRead(xaccelPin);
  yaccelValue = analogRead(xaccelPin);
  //Movimiento del punto si esta dentro de los margenes
  //Movimiento de la fila (depende del eje y del acelerometro)
  if (yaccelValue > 400 && filaMovil < 5) filaMovil++;
  if (yaccelValue < 270 && filaMovil > 1) filaMovil--;
  //Movimiento de la columna (depende del eje x del acelerometro)
  if (xaccelValue > 400 && columnaMovil > 1)columnaMovil--;
  if (xaccelValue < 270 && columnaMovil < 7) columnaMovil++;
}

void loop() {
  currentMillis = millis(); // lectura del tiempo actual
  encenderpixels();      // enciende los pixels
  // Solo mueve el movil cada 200ms
  if (currentMillis - tiempoAnterior > 200) {
    moverpixel();
    tiempoAnterior = currentMillis;
  }
  // Deteccion de si coinciden pixel movil y fijo
  if ( filaFijo == filaMovil && columnaFijo == columnaMovil) {
    matriz.cleanMatrix();
    // zumbador avisando de que lo has conseguido
    digitalWrite(zumbadorPin, HIGH);
    delay(150);
    digitalWrite(zumbadorPin, LOW);
    // Nuevas coordenadas i,j para pixel fijo
    filaFijo = random (1, 6);
    columnaFijo = random (1, 8);
  }
}
