//Proyecto Diseñado por: Carlos Duran 

long tiempo;
int trig = A0; //Trigger
int echo = A1; //Echo
float distancia; // variable con punto decimal 

void setup() {
  pinMode(trig, OUTPUT); //Declaramos pin 7 como salida
  pinMode(echo, INPUT); //Declaramos pin 8 como salida
  Serial.begin(9600); // Inicializamos el monitor 
}

void loop() {
  digitalWrite(trig, HIGH); // Envio de pulso ultrasonico
  delayMicroseconds(10); // Tiempo de reproduccion
  digitalWrite(trig, LOW); // Silenciar pulso ultrasonico
  
  tiempo =(pulseIn(echo,HIGH)/2);// Recibir el pulso de repuesta 
  // se divide ntre 2 porque el pulso va y viene

  //Ecuacion de fisica v = d/t
  // Despejamos:L d= v*t
  // sabemos que la velocidad del sonido viaja a 343 m/s
  // El tiempo sera calculado por el tiempo que tarda en ir y regresar el pulso

   distancia = float (tiempo*0.0343); //Tiempo en millonesima de segundo
   
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm"); 
  delay(500); //Cada 0.5 segundos
}
