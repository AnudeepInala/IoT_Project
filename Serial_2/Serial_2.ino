#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8,7);
void setup() {
  pinMode(6,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}
void loop() {
  char r;
  if(Serial.available()>0)
  {
     r=Serial.read();
     if(r=='1')
     {
      digitalWrite(6,1);
      lcd.setCursor(0,0);
      lcd.print("Onn");
     }
     if(r=='0')
     {
      digitalWrite(6,0);
      lcd.print("Off");
     }
  }
}
