/*
 * Pulsador LED con Memoria
 * Kiwibot- Jose Pujol
 */
// constantes que no cambian
// se usan para establecer los pines

const int buttonPin = 3;     // el numero del pin del pulsador
const int ledRPin = 6;       // el numero de pin del led

// variables que cambian
int ledState = LOW;         // Estado actual del led apagado
int buttonState = 0;            // variable para almacenar el estado del pulsador

void setup() {
  // inicializa el pulsador como entrada
  pinMode(buttonPin, INPUT);
  // inicializa el led como salida
  pinMode(ledRPin, OUTPUT);

}

void loop() {
  // lee el estado del pulsador y lo almacena en vble
  buttonState = digitalRead(buttonPin);

  // revisa si el pulsador esta presionado
  if (buttonState == HIGH) {
    // si el estado del led es bajo
    // lo pone alto
    if (ledState == LOW) {
      ledState = HIGH;
    }
    else {
      ledState = LOW;
    }
    // tiempo que evita que el programa siga cumpliendo la condicion
    delay(200);
  }
  // establece el estado del LED:
  digitalWrite(ledRPin, ledState);

}


