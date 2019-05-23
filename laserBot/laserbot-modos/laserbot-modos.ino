/*
  Programa para control de printbot kiwibot por APP y HC06.
  Desarrollado por Miguel Granero y Jose Pujol usando el hardware de kiwibot  \ www.kiwibot.es /
  Con este programa podras controlar un printbot kiwibot gracias a su APP, esta envia señales y arduino las sintetiza segun le diga este codigo.
  Necesitaras la APP, la puedes encontrar en Google Play.
  Como utilizarla:
   Botones cruzeta: Estos botones te serviran para controlar el coche en modo manual.
   Boton de el centro de la cruzeta: Este boton sirve para acceder al bluetooth y conectar la APP con Arduino.
   Boton bajo izquierdo: Si lo pulsas sonara el timbre del kiwibot.
   Boton bajo derecho: Este boton sirve para cambiar entre modos de control, inicialmente esta en automatico.
*/
//Declaramos los pines necesarios
//Pin del timbre.
const int buzzerPin = 10;

//Variable que usaremos para leer el serial.
int ch;

//Pines de los servomotores continuos.
int M7 = 7;
int M4 = 4;

//Variable de memoria que usaremos para guardar el ultimo dato enviado.
int memory;

/*Estos dos pines son los necesarios para el sensor de distancia por ultrasonido.
  Uno lo envia y el otro lo recibe y segun el tiempo que haya tardado se averigua la distancia*/
const int triggerPin = 11;
const int echoPin = 12;

//Esta variable la usaremos con una pequeñe formula para sacar de ella la distancia.
float tiempo;

//En esta varible guardaremos las distancia gracias a una pequeña formula.
float distance;

//Esta variable nos especifica la direccion de giro del kiwibot.
int dir;

//Estas variables las usaremos para los millis, funciones del reloj interno de arduino.
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long anteriorMillis = 0;

//Esta variable es la que nos especifica cuando puede el printbot girar y cuando no.
int x;

//Esta variable es la que usaremos para especificar si el printbot debe de estar en control automatico o manual.
int autom = 0;

void setup() {
  //Esta pieza de codigo solo se ejecuta una sola vez, aqui especificamos si cada pin es OUTPUT o INPUT por ejemplo.
  Serial.begin(9600);//Especificamos la velocidad de transmision del serial.
  pinMode(M7, OUTPUT);
  pinMode(M4, OUTPUT);
  randomSeed(analogRead(A0));//Cojemos unos valores que usaremos despues para escojer la direccion de giro. En este caso son los valores del pin A0.
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

}
void backward() {//Pieza de codigo que le especifica al kiwibot la direccion de sus ruedas. Hacia detras.
  digitalWrite(M4, HIGH);
  digitalWrite(M7, HIGH);
  delayMicroseconds(1000);
  digitalWrite(M4, LOW);
  delayMicroseconds(1000);
  digitalWrite(M7, LOW);
  delayMicroseconds(18000);
}

void frontwards() {//Pieza de codigo que le especifica al kiwibot la direccion de sus ruedas. Hacia delante.
  digitalWrite(M7, HIGH);
  digitalWrite(M4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(M7, LOW);
  delayMicroseconds(1000);
  digitalWrite(M4, LOW);
  delayMicroseconds(18000);
}

void left() { //Pieza de codigo que le especifica al kiwibot la direccion de sus ruedas. Giro a la izquierda.
  digitalWrite(M7, HIGH);
  digitalWrite(M4, HIGH);
  delayMicroseconds(2000);
  digitalWrite(M7, LOW);
  digitalWrite(M4, LOW);
  delayMicroseconds(18000);
}

void right() { //Pieza de codigo que le especifica al kiwibot la direccion de sus ruedas. Giro a la derecha.
  digitalWrite(M7, HIGH);
  digitalWrite(M4, HIGH);
  delayMicroseconds(1000);
  digitalWrite(M7, LOW);
  digitalWrite(M4, LOW);
  delayMicroseconds(19000);
}

void stopA() {//En este pieza de codigo paramos ambos motores.
  digitalWrite(M7, LOW);
  digitalWrite(M4, LOW);
}

int medirdistancia() { //Esto lo usaremos para medir la distancia con una formula.
  digitalWrite(triggerPin, LOW);//El estado inicial del trigger debe ser apagado
  delayMicroseconds(5);//Esperamos un pequeño lapso de tiempo
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);//Lo encendemos y esperamos 10 microsegundos antes de volverlo a apagar
  digitalWrite(triggerPin, LOW);
  tiempo = pulseIn(echoPin, HIGH, 25000); //Aqui calculamos el tiempo que ha tardado en rebotar, fijandole un tiempo limite para que no se queda pillado
  distance = tiempo * 0.01715; //Calculamos la distancia con esta pequeña formula
  return distance;//Devolvemos la distancia obtenida para poder usarla mas adelante
}

void loop() {
  if (Serial.available() > 0) {
    ch = Serial.read(); //Si hay algo almacenado en el serial, lo fijamos en esta variable.
  }
  if (ch == 'H') {//Activamos el control autmatico.
    autom = 1;
  }
  if (ch == 'L') {//Desactivamos el control aumatico.
    autom = 0;
  }
  currentMillis = millis();//Cada 100 milisegundos del reloj interno de arduino se ejecuta esta pieza de codigo en la que medimos la distancia.
  if (currentMillis - previousMillis >= 100) {
    medirdistancia();
    previousMillis = currentMillis;
  }
  if (autom == 0) { //Esto solo se ejecutara si el modo automatico esta apagado.
    //Guarda el mensaje que haya en el serial para que no se pierda con el resto de mensajes.
    if (ch == 'f') {
      memory = 'f';
    }
    if (ch == 'l') {
      memory = 'l';
    }
    if (ch == 'r') {
      memory = 'r';
    }
    if (ch == 'b') {
      memory = 'b';
    }
    if (ch == 's') {
      memory = 's';
    }

    //Aqui hacemos con los motores lo que hayamos recibido por el serial, como hemos fijado arriba
    //Por ejemplo si hemos recibido una s por el serial, aqui abajo se especifica que el coche se pare.
    if (memory == 's') {
      stopA();
      digitalWrite(buzzerPin, LOW);
    }
    if (memory == 'f') {//Si hemos recibido una f (hacia adelante) y no hay nada a 15 cm de el empieza a andar, si no se para y pita como medida de seguridad
      if (distance < 16 && distance > 0) {
        digitalWrite(buzzerPin, HIGH);
      }
      else {
        digitalWrite(buzzerPin, LOW);
        frontwards();
      }
    }
    //Realizamos el resto de movimientos (izquierda, derecha, hacia atras y encender y apagar el timbre).
    if (memory == 'l') {
      left();
    }
    if (memory == 'b') {
      backward();
    }
    if (memory == 'r') {
      right();
    }
    if (ch == 'Z') {
      digitalWrite(buzzerPin, HIGH);
    }
    if (ch == 'z') {
      digitalWrite(buzzerPin, LOW);
    }
  }

  else { //Aqui empezamos con el modo automatico.
    if (distance > 0 && distance < 16) { //Si el coche detecta un obstaculo a menos de 16cm de el:
      if (x == 0) { //Si x es 0 elije un numero aleatorio entre 0 y 9. Esta condicion es necesaria para que no este generando numeros todo el rato y gire muy poco.
        dir = random(0, 9);
        x = 1; //Pone x a 1 para que se puede ejecutar el millis de mas arriba.
      }
      if (currentMillis - anteriorMillis >= 1000 && x == 1) { //Cada 1000 milisegundos del reloj interno de arduino se ejecuta esta pieza de codigo en la que daremos permiso a que despues se cree un numero aleatorio.
        anteriorMillis = currentMillis;
        x = 0;
      }
      //Aqui simplemente segun el numero generado se gira hacia un lado u otro.
      if (dir < 5) {
        left();
      }
      else {
        right();
      }
    }
    else { //Si no ha detectado nada a 15cm de el, sigue hacia adelante.
      frontwards();
    }
  }
}
