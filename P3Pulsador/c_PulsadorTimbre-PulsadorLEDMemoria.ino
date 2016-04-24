
/*
 * Pulsador Izquierdo- timbre
 * Pulsador Derecho - LED memoria
 * kiwibot- Jose Pujol
 */
// constantes que no cambian
// se usan para establecer los pines

const int buttonLPin = 2;     // el numero del pin del pulsador izquierdo
const int buttonRPin = 3;     // el numero del pin del pulsador derecho
const int buzzerPin =  10;      // el numero de pin del zumbador
const int ledRPin = 6;       // el numero de pin del led rojo

// variables que cambian
int ledState = LOW;         // Estado actual del led apagado
int buttonLState = 0;            // variable para almacenar el estado del pulsador
int buttonRState = 0;            // variable para almacenar el estado del pulsador


void setup() {
  // inicializa los pulsadores como entradas
  pinMode(buttonLPin, INPUT);
  pinMode(buttonRPin, INPUT);
  // inicializa el led como salida
  pinMode(ledRPin, OUTPUT);
  // inicializa el zumbador como salida
  pinMode(buzzerPin, OUTPUT);

}

void loop() {

  // lee el estado de los pulsadores y los almacena
  buttonLState = digitalRead(buttonLPin);
  buttonRState = digitalRead(buttonRPin);

  // revisa si el pulsador R esta presionado
  if (buttonLState == HIGH) {
    // enciende el pulsador
    digitalWrite(buzzerPin, HIGH);
  }
  else {
    // apaga el pulsador
    digitalWrite(buzzerPin, LOW);
  }

  // revisa si el pulsador L esta presionado
  if (buttonRState == HIGH) {
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
