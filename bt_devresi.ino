#include "BluetoothSerial.h"
BluetoothSerial SerialBT;                                                 

void setup() {
  Serial.begin(115200);                                                 
  SerialBT.begin("DeneyapKart"); 
  Serial.println("\nCihaz yayin yapmaya basladi, eslesme yapilabilir!");
}

void loop() {
  while(Serial.available() == 0 && SerialBT.available() == 0);           
  if (Serial.available() > 0) 
  {
    SerialBT.write(Serial.read());                                        
  }
  if (SerialBT.available() > 0) 
  {
    Serial.write(SerialBT.read());                                       
  }
  delay(20);
}