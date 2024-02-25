int c=0;
int f,b,l,r;
void setup() {
  
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  f=digitalRead(13);
  b=digitalRead(12);
  l=digitalRead(11);
  r=digitalRead(10);
  if(c==0)
  {
    if(f==0)
    {
      digitalWrite(9,1);
      digitalWrite(8,0);
      digitalWrite(7,1);
      digitalWrite(6,0);
    }
  }
  if(f==1)
  {
    digitalWrite(9,0);
    digitalWrite(8,1);
    digitalWrite(7,0);
    digitalWrite(6,1);
    delay(2000);
    c=c+1;
  }
  if(r==1)
  {
    digitalWrite(9,0);
    digitalWrite(8,0);
    digitalWrite(7,1);
    digitalWrite(6,0);
    delay(1000);
    c=c+1;
  }
  if(l==1)
  {
    digitalWrite(9,1);
    digitalWrite(8,0);
    digitalWrite(7,0);
    digitalWrite(6,0);
    delay(1000);
    c=c+1;
   }
}
