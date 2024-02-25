void setup() {
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  int v;
  v=digitalRead(13);
  if(v==1)
  {
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,0);
  }
  else
  {
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,1);
  }
}
