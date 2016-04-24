/*
Semaforo con 3 estados verde, amarillo y rojo
verde 10s
amarillo 2s
rojo 5s
LED RGB
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

  // estado semaforo amarillo
  digitalWrite(ledRPin, HIGH); // escribe 5v en el pin del LED rojo
  digitalWrite(ledGPin, HIGH); // escribe 5v en el pin del LED verde
  delay(2000);    // espera dos segundos

  // estado semaforo rojo
  digitalWrite(ledGPin, LOW); // escribe 0v en el pin del LED verde
  digitalWrite(ledRPin, HIGH); // escribe 5v en el pin del LED rojo
  delay(5000);    // espera cinco segundos
}
