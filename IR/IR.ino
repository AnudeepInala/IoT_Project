void setup() {
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  int a=0;
  a = digitalRead(13);
  if(a!=0)
  {
    digitalWrite(12,1);
  }
  else
  {
    digitalWrite(12,0);
  }
}
