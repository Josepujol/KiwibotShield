/*
 Imprime los valores del Joystick X,Y por puerto serie
 Kiwibot- Jose Pujol
 */

// declaramos los pines
const int joyXPin = A4; // selecciona el pin de entrada para el joystick x
const int joyYPin = A5; // selecciona el pin de entrada para el joystick y

// variables que almacenan los datos
int joyXValue = 0; // variable para almacenar los valores del joystick y
int joyYValue = 0; // variable para almacenar los valores del joystick y

void setup() {
  // abre el puerto serie
  // y establece la velocidad de conexion en baudios
  Serial.begin(9600);
}

void loop() {
  // lee los valores de los sensores
  joyXValue = analogRead(joyXPin);
  joyYValue = analogRead(joyYPin);

  // Imprime el valor del joyX
  Serial.print(joyXValue);
  // Imprime un espacio
  Serial.print("\t");
  // Imprime el valor del joyY y añade retorno de carro
  Serial.println(joyYValue);
  // tiempo de espera para visibilidad
  // y para no saturar el puerto serie (nota)
  delay(1000);
}
