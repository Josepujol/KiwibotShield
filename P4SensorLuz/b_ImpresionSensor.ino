/*
  Analog Input
 Impresion del valor de un sensor por el puerto serie
 Kiwibot- Jose Pujol 
 */

const int ldrPin = A0;    // establece el pin de la LDR
int ldrValue = 0;  // variable para almacenar el valor del sensor 

void setup() {
  // abre el puerto serie
  // y establece la velocidad de conexion en baudios
  Serial.begin(9600);
}

void loop() {
  // lee el valor del sensor
  ldrValue = analogRead(ldrPin);    
  // Imprime un texto
  Serial.print("Valor LDR=");
  // Imprime el valor de la variable por el puerto serie
  Serial.println(ldrValue);
  // tiempo de espera para visibilidad
  // y para no saturar el puerto serie (nota)
  delay(1000);                  
}

