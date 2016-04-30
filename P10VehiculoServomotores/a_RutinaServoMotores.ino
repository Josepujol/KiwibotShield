/*
Rutina para comprobar que los servomotores funcionan correctamente
y el printBot se mueve:
adelante, atras, izquierda, derecha
Alberto Pumar, Jose Pujol revisado noviembre 2015
 */

// Pines de servomotores:
int servoLPin = 7; // Pin del servo izquierda
int servoRPin = 4;  // Pin del servo derecha

void setup() {
  pinMode (servoRPin, OUTPUT);
  pinMode (servoLPin, OUTPUT);
}

void loop() {
// repeticion de cada rutina
// 500*20ms= 
  for (int i = 0; i < 500; i++) {
    go_forward();
  }
  delay(2000);
  for (int i = 0; i < 500; i++) {
    go_back();
  }
  delay(2000);
  for (int i = 0; i < 500; i++) {
    turn_left();
  }
  delay(2000);
  for (int i = 0; i < 500; i++) {
    turn_right();
  }
  delay(2000);
}




//Rutina para que el coche avance
void go_forward() {
  digitalWrite(servoRPin, HIGH);
  digitalWrite(servoLPin, HIGH);
  delayMicroseconds(1000);// 1 - 1500 atras, de 1500 a 3000 delante
  digitalWrite(servoLPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(servoRPin, LOW);
  delayMicroseconds(18000);
}

//Rutina para que el coche retroceda

void go_back() {
  digitalWrite(servoRPin, HIGH);
  digitalWrite(servoLPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(servoRPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(servoLPin, LOW);
  delayMicroseconds(18000);
}

//Rutina para que el coche gire a la derecha
void turn_left() {
  digitalWrite(servoRPin, HIGH);
  digitalWrite(servoLPin, HIGH);
  delayMicroseconds(2000);// 1 - 1500 atras, de 1500 a 3000 delante
  digitalWrite(servoRPin, LOW);
  digitalWrite(servoLPin, LOW);
  delayMicroseconds(18000);
}

//Rutina para que el coche gire a la izquierda
void turn_right() {
  digitalWrite(servoRPin, HIGH);
  digitalWrite(servoLPin, HIGH);
  delayMicroseconds(1000);// 1 - 1500 atras, de 1500 a 3000 delante
  digitalWrite(servoRPin, LOW);
  digitalWrite(servoLPin, LOW);
  delayMicroseconds(19000);
}
