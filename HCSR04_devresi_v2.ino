#include "deneyap.h"
#include <Deneyap_Servo.h>
#include <HCSR04.h>

#define SERVOPIN1 D0     
#define trig_pin D14       
#define echo_pin D15      
#define buzzer_pin D1      

UltraSonicDistanceSensor distanceSensor(trig_pin, echo_pin);
Servo myservo;

int sensor1, sensor2;
int pos = 0;
long sure;
long uzaklik;

void setup() 
{
  myservo.attach(SERVOPIN1);
  Serial.begin(115200);   

}
void loop() 
{
  uzaklik = distanceSensor.measureDistanceCm();
  if(uzaklik < 15)      
  digitalWrite(buzzer_pin, HIGH); 
  if(uzaklik >= 15)       
  digitalWrite(buzzer_pin, LOW);
  Serial.print("Uzaklık");    
  Serial.print(uzaklik); 
  Serial.println("CM"); 
  pos=uzaklik*(180/40);
  myservo.write(pos);
  delay(5);
}