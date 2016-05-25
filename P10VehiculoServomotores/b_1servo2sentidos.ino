/*
Programa para controlar sentido giro servomotor continuo
Hacemos girar el motor en uno y otro sentido con paradas intermedias
Jose Pujol Mayo 2016
*/

// pin conexion servomotor
const int servoR = 4;

void setup() {
  // servomotor salida digital
  pinMode(servoR, OUTPUT);
}


void loop() {
  // repetimos 500 veces rutina forward
  for (int i = 0; i < 500; i++) {
  forward();
  }
  // paramos el servo durante 2s
  delay(2000);
    // repetimos 500 veces rutina backward
  for (int i = 0; i < 500; i++) {
  backward();
  }
   // paramos el servo durante 2s
  delay(2000);
}


void forward() {
  // 1 pulso en periodo de 20ms
  digitalWrite(servoR, HIGH);
  delayMicroseconds(1000);
  digitalWrite(servoR, LOW);
  delayMicroseconds(19000);
}

void backward() {
  // 2 pulsos en periodo de 20ms
  digitalWrite(servoR, HIGH);
  delayMicroseconds(2000);
  digitalWrite(servoR, LOW);
  delayMicroseconds(18000);
}
