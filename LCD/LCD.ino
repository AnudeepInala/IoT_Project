#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8,7); //RS, R/W, En, D4, D5, D6, D7
void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("1st line");
  lcd.setCursor(0,1);
  lcd.print("2nd line");
  delay(100);
  lcd.clear();
  delay(100);
}
