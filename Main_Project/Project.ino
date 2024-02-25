#include <Q2HX711.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,11,10,9,8);

const byte hx711_data_pin = 4;
const byte hx711_clock_pin = 3;

float y1 = 20.0; // calibrated mass to be added
long x1 = 0L;
long x0 = 0L;
float avg_size = 10.0; // amount of averages for each mass measurement

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin); // prep hx711

void setup() {
  pinMode(5,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600); // prepare serial port
  delay(1000); // allow load cell and hx711 to settle
  // tare procedure
  for (int ii=0;ii<int(avg_size);ii++){
    delay(10);
    x0+=hx711.read();
  }
  x0/=long(avg_size);
  Serial.println("Add Calibrated Mass");
  lcd.begin(16,2);
  lcd.print("Add Weight");
  // calibration procedure (mass should be added equal to y1)
  int ii = 1;
  while(true){
    if (hx711.read()<x0+10000){
    } else { 
     ii++;
      delay(2000);
      for (int jj=0;jj<int(avg_size);jj++){
        x1+=hx711.read();
      }
      x1/=long(avg_size);
      break;
    }
  }
  Serial.println("Calibration Complete");
  lcd.begin(16,2);
  lcd.print("Completed");
}

void loop() {
  // averaging reading
  long reading = 0;
  for (int jj=0;jj<int(avg_size);jj++){
    reading+=hx711.read();
  }
  reading/=long(avg_size);
  // calculating mass based on calibration and linear fit
  float ratio_1 = (float) (reading-x0);
  float ratio_2 = (float) (x1-x0);
  float ratio = ratio_1/ratio_2;
  float mass = y1*ratio;
  mass=mass*11;
  if(mass<20.0)
  {
    digitalWrite(5,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);

  }
  else
  {
    digitalWrite(5,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);

  }
  Serial.print("Mass:");
  Serial.print(mass);
  lcd.setCursor(0,0);
  lcd.print("Weight:  ");
  lcd.setCursor(0,1);
  lcd.print(mass);
  Serial.println("g");
  delay(2000);
}
