#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<math.h>

int therm= A0;
float R=10000,logr2,R2,Tc,T,vo; //R=10k
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
   
}


void loop()
{
  vo = analogRead(therm);
  R2 = R * (1024.0 /vo - 1.0);
  logr2 = log(R2);
  T = (1.0 / (c1 + c2*logr2 + c3*logr2*logr2*logr2));
  Tc = T - 273.15;

  lcd.setCursor(1,0); // 0=first raw ,1=2 nd position in array
  lcd.print("Temperature : ");
  lcd.setCursor(3,1); 
  lcd.print(Tc);
  lcd.println(" Celsius");   
 
 delay(500);
}
