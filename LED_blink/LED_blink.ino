void setup() {
  pinMode(A0,OUTPUT);
}

void loop() {
    digitalWrite(A0,1);
    delay(1000);
    digitalWrite(A0,0);
    delay(1000);
}
