/*
Programa para controlar 2 servomotores continuos
Derecho sentido horario, Izquierdo sentido antihorario
Para que vehiculo avance
Jose Pujol Mayo 2016
*/

// pin conexion servomotor
const int servoR = 4; // servo derecha
const int servoL = 7; // servo izquierda

void setup() {
  // servomotores salida digital
  pinMode(servoR, OUTPUT);
  pinMode(servoL, OUTPUT);
}


void loop() {
// servoR 2 pulsos periodo 20ms
// servoL 1 pulso periodo 20ms
  digitalWrite(servoR, HIGH);
  digitalWrite(servoL, HIGH);
  delayMicroseconds(1000);
  digitalWrite(servoL, LOW);
  delayMicroseconds(1000);
  digitalWrite(servoR, LOW);
  delayMicroseconds(18000);
}
