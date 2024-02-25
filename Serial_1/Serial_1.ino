#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8,7);
void setup()
{
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}
void loop()
{
  int t,ldr;
  char v;
  t=analogRead(A1);
  ldr=analogRead(A0);
  if(Serial.available()>0)
  {
    v=Serial.read();
    if(v=='0' or (t<50 and ldr>500))
    {
      digitalWrite(6,0);
      digitalWrite(5,0);
      lcd.setCursor(0,0);
      lcd.print("Both OFF");
    }
    if(v=='1' or t>51)
    {
      digitalWrite(6,1);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan On");
    }
    if(v=='2' or t<51)
    {
      digitalWrite(6,0);
      lcd.clear();
      lcd.print("Fan Off");
    }
    if(v=='3' or ldr>500)
    {
      digitalWrite(5,1);
      lcd.setCursor(0,1);
      lcd.print("Light On");
    }
    if(v=='4' or ldr<500)
    {
      digitalWrite(5,0);
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Light Off");
    }
  }
}
