/*
Semaforo verde, amarillo y rojo
Usa LED RGB
verde 10s
amarillo 2s- parpadeo de 0.2s
rojo 5s
Kiwibot- Jose Pujol
*/

// Declaracion de variables de tipo constante entero
const int ledRPin = 6; // LED rojo asociado al pin 5
const int ledGPin = 9; // LED verde asociado al pin 9

// la funcion set up se ejecuta una sola vez
void setup() {
  // inicializa el pin 5,6,9 como una salida digital
  pinMode(ledRPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {
  // estado semaforo verde
  digitalWrite(ledRPin, LOW); // escribe 0v en el pin del LED rojo
  digitalWrite(ledGPin, HIGH); // escribe 5v en el pin del LED verde
  delay(10000);    // espera diez segundos

  // estado semaforo amarillo parpadeante
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledRPin, HIGH); // escribe 5v en el pin del LED rojo
    digitalWrite(ledGPin, HIGH); // escribe 5v en el pin del LED verde
    delay(200);    // espera dos decimas de segundo
    digitalWrite(ledRPin, LOW); // escribe 5v en el pin del LED rojo
    digitalWrite(ledGPin, LOW); // escribe 5v en el pin del LED verde
    delay(200);    // espera dos decimas de segundo
  }

  // estado semaforo rojo
  digitalWrite(ledRPin, HIGH); // escribe 5v en el pin del LED rojo
  digitalWrite(ledGPin, LOW); // escribe 0v en el pin del LED verde
  delay(5000);    // espera cinco segundos
}
