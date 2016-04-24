/*
Interruptor crepuscular
Usando LED RGB y LDR
Kiwibot-Jose Pujol
 */
// variables constantes para los pines
const int ldrPin = A0;    // establece el pin de la LDR
const int ledRPin = 6; // establece el pin del LED rojo
const int ledGPin = 9; // establece el pin del LED verde
const int ledBPin = 5; // establece el pin del LED azul

// variable para almacenar el valor del sensor
int ldrValue = 0;
void setup() {
  // establece los LEDs como una salida
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);
  // si el valor es menor enciende los LEDs
  if (ldrValue < 200) {
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledBPin, HIGH);
  }
  // sino los apaga
  else {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
}


