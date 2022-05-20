/*
Codigo de Calibracion  
*/

const int trig = A0; // Pin trigger.
const int echo = A1; // Pin echo.

void setup() 
{ 
   
  Serial.begin(9600); // inicializar la comunicación en serie
  pinMode(trig, OUTPUT); // Entrada
  pinMode(echo, INPUT); // Salida
} 
  
void loop() 
{ 
  
   makePing(); //Envían una ráfaga sónica y miden el tiempo hasta el eco, calculan la distancia.
} 

void makePing()
{
// Establecer variables para la duración del ping 
// y el resultado de la distancia en pulgadas y centímetros:
long duration, cm;

  // El PING ))) se dispara con un pulso HIGH de 2 o más microsegundos.
  // Dar un breve pulso LOW de antemano para asegurar un pulso HIGH limpio:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); // The sonics burst has 0.340 cm of length.
  digitalWrite(trig, LOW);

  // Un pulso ALTO cuya duración es el tiempo (en microsegundos) desde el envío
  // del ping a la recepción de su eco en un objeto.
  duration = pulseIn(echo, HIGH);

  // convertir el tiempo en una distancia

  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  // La velocidad del sonido es de 340 m/s o 29,4117647 microsegundos por centímetro.
  // El ping viaja de ida y vuelta, así que para encontrar la distancia del
  // objeto tomamos la mitad de la distancia recorrida.
  
  //return (microseconds / 29.4117647 / 2.); // sin calibración.
  
  return (microseconds / 29,4117647 / 2,-0,37167)/1;
  
  // Los dos últimos números provienen de la calibración de mi propio módulo HC-SR04
  // Para hacer eso, hay que hacer una regresión lineal con la medida real
  // y la medida dada por el programa.
}
