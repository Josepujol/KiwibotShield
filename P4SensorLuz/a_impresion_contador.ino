/*
  Impresion por puerto serie de un contador
  Kiwibot- Jose Pujol
 */

int contador = 0;  // variable para almacenar el valor del contador 

void setup() {
  // abre el puerto serie
  // y establece la velocidad de conexion en baudios
  Serial.begin(9600);
}

void loop() {
 
  // Imprime un texto
  Serial.print("CONTADOR=");
  // Imprime el valor de la variable por el puerto serie
  Serial.println(contador);
  // tiempo de espera para visibilidad
  // y para que aumnete el contador cada segundo
  delay(1000);                 
  contador ++; // se incrementa el valor del contador en 1
}

