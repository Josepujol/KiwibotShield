/*
Parpadeo
Enciende y apaga un LED una sola vez
*/

// declaracion de variables
int ledRPin = 6; // LED rojo asociado al pin 9

// la funcion set up se ejecuta una sola vez
void setup() {
  pinMode(ledRPin, OUTPUT); // inicializa el pin 9 como una salida digital
  digitalWrite(ledRPin, HIGH); // escribe 5v en el pin del LED
  delay(1000); // espera un segundo
  digitalWrite(ledRPin, LOW); // escribe 0v en el pin del LED
  delay(1000); // espera un segundo
}

// la funcion loop se ejecuta repetidamente de forma infinita
void loop() {
  // No contiene nada
}
