#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8,7);
void setup() {
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  int v;
  v=digitalRead(6);
  if(v==1)
  {
    digitalWrite(5,1);
    digitalWrite(4,1);
    lcd.setCursor(0,0);
    lcd.print("Person Entered");
    delay(3000);
  }
  else
  {
    digitalWrite(5,0);
    digitalWrite(4,0);
    lcd.setCursor(0,0);
    lcd.print("NoPersonDetected");
  }
}
