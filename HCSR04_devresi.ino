#include <HCSR04.h>

#define trigPin D0
#define echoPin D1

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

void setup() {
Serial.begin(115200);
}
void loop() {
  Serial.print("Mesafe: ");
Serial.println(distanceSensor.measureDistanceCm()); 
delay(500);
}