#include <Deneyap_Servo.h>

int  deger = 0;
int aci;

Servo servo_D9;

void setup() {
  Serial.begin(115200);

  servo_D9.attach(D9);
}

void loop() {
  deger = analogRead(A0);
  delay(50);
  aci = map(deger,0,4095,0,180);
  Serial.print("Açı: ");
  Serial.println(aci);
  servo_D9.write(aci);
  delay(15);

}