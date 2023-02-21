int trigPin = 11;    // Trigger, číslo pinu kam je připojen
int echoPin = 12;    // Echo, číslo pinu kam je připojen
long duration; // vzdálenost
long cm; //centimetry
 
void setup() {
  //rate portu
  Serial.begin (9600);
  //definujeme input jako
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) * 0.0343;     // Musíme vydělat čas 2, protože ta vlna tam musí doletět a pak se vrátit zpátky, my chceme jen vzdálenost tam, ne i zpět
  
  Serial.print("Vzdalenost:  ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(1000);
}