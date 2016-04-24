/*
 Controla la lumninosidad LED con Joystick eje x
 Kiwibot- Jose Pujol
 */

// declaramos los pines
const int joyXPin = A4; // selecciona el pin de entrada para el joystick x
const int ledRPin = 6;  // selecciona pin para el LED

// variables que almacenan los datos
int joyXValue = 0; // variable para almacenar los valores del joystick x
int joyXMapvalue=0;  // variable que almacena el valor del sensor mapeado 0-255

void setup() {
  // abre el puerto serie
  // y establece la velocidad de conexion en baudios
  Serial.begin(9600);
}

void loop() {
  // lee los valores de los sensores
  joyXValue = analogRead(joyXPin);
  joyXMapvalue = map(joyXValue, 0, 1023, 0, 255);

  // escribimos el valor en analogico
  analogWrite(ledRPin, joyXMapvalue);
}
