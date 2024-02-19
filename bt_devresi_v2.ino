#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int led1 = D12;
int led2 = D13;
int led3 = D14;
void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  SerialBT.begin("Deneyap Kart"); 
}
void loop() {
  if (SerialBT.available() > 0) {
    int veri = SerialBT.read();
    if (veri == 1) {             
      digitalWrite(led1, HIGH);
    } if (veri == 2) {           
      digitalWrite(led1, LOW);
    } if (veri == 3) {          
      digitalWrite(led2, HIGH);
    } if (veri == 4) {           
      digitalWrite(led2, LOW);
    } if (veri == 5) {           
      digitalWrite(led3, HIGH);
    } if (veri == 6) {          
      digitalWrite(led3, LOW);
    }
    delay(10);
  }
}