/*
 *  Programa para encender y apagar un LED gradualmente
 *  Subida y bajada de 2,5s
 *  Basado en el programa Fading de Arduino
 *  kiwibot- Jose Pujol
 */

const int ledRPin = 6; // LED rojo conectado a Pin 9

void setup() {
  // nada que declarar en el set up
}
void loop() {
  // Encendido gradual del LED en 2,5s
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // establece el valor de 0 a 255
    analogWrite(ledRPin, fadeValue);
    // espera 50 ms para ver el efecto de dimerizacion
    delay(50);
  }
  // Apagado gradual del LED en 2,5
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // establece el valor de 255 a 0
    analogWrite(ledRPin, fadeValue);
    // espera 50 ms para ver el efecto de dimerizacion
    delay(50);
  }
}
