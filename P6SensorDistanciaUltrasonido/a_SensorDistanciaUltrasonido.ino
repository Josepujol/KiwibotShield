/*
Programa para medir la distancia
 con el sensor de ultrasonidos HC SR 04
 Kiwibot- jose Pujol
 */
// Conexion pines del sensor de distancia
const int triggerPin = 11; // Pin donde conectamos el emisor
const int echoPin = 12; // Pin donde conectamos el receptor

// Variable para almacenar la distancia
int distance = 0;

void setup() {
  Serial.begin(9600); // Abrimos el puerto serie
  pinMode(triggerPin, OUTPUT); // Configuramos trigger como salida digital
  pinMode(echoPin, INPUT); // Configuramos echo como entrada digital
}
void loop() {
  //Inicializamos el sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  // Enviamos una señal activando la salida trigger durante 10 microsegundos
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Medimos el ancho del pulso, cuando la lectura sea HIGH
  // devuelve el tiempo transcurrido en microsegundos
  distance = pulseIn(echoPin, HIGH);
  // Calculamos la distancia en cm
  distance = distance * 0.01715;
  // Enviamos los datos medidos a traves del puerto serie
  Serial.println (distance);
  delay(100); // Esperamos 100ms
}
