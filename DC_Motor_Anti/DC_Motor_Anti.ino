void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  digitalWrite(13,1);
  digitalWrite(12,0);
  delay(2000);
  digitalWrite(13,0);
  digitalWrite(12,1);
  delay(2000);
  digitalWrite(13,0);
  digitalWrite(12,0);
  delay(2000);
}
