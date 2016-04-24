/*
Vumetro de medicion de la luz
Usando LED RGB y LDR
Escala de colores desde 
Azul= poca luz, verde, amarillo, rojo, rojo parpadeante= mucha luz
 Kiwibot- Jose Pujol
 */

// variables constantes para los pines
const int ldrPin = A0;    // establece el pin de la LDR
const int ledRPin = 6; // establece el pin del LED rojo
const int ledGPin = 9; // establece el pin del LED verde
const int ledBPin = 5; // establece el pin del LED azul

// variable para almacenar el valor del sensor
int ldrValue = 0;

void setup() {
  // establece los LED como salidas
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);
  // si el valor ldr es menor 200 LED azul
  if (ldrValue < 200) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, HIGH);
  }
  // si el valor ldr entre 200 y 400 LED verde
  if (ldrValue >= 200 && ldrValue < 400) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledBPin, LOW);
  }
  // si el valor ldr entre 400 y 600 LED amarillo
  if (ldrValue >= 400 && ldrValue < 600) {
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledGPin, HIGH);
    digitalWrite(ledBPin, LOW);
  }
  // si el valor ldr entre 600 y 800 LED rojo
  if (ldrValue >= 400 && ldrValue < 600) {
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);
  }
  // si el valor ldr es mayor 800 LED rojo parpadeo
  if (ldrValue > 800) {
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);
    delay (500);
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledGPin, LOW);
    digitalWrite(ledBPin, LOW);
    delay (500);
  }

}



