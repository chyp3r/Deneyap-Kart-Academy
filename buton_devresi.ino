int  buton;

void setup() {
  pinMode(D0, INPUT);
  pinMode(D1, OUTPUT);
}

void loop() {
  buton = digitalRead(D0);
  if (buton == HIGH) {
    digitalWrite(D1, LOW);
  } else {
    digitalWrite(D1, HIGH);
  }
}