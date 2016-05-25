/*
Programa para hacer girar un servomotor continuo
en un sentido de giro
Jose Pujol Mayo 2016
*/

// pin conexion servomotor
const int servoR = 4;

void setup() {
  // servomotor salida digital
  pinMode(servoR, OUTPUT);
}

void loop() {
  // damos 1 pulso de 1ms- periodo 20ms
  digitalWrite(servoR, HIGH);
  delayMicroseconds(1000);
  digitalWrite(servoR, LOW);
  delayMicroseconds(19000);
}
