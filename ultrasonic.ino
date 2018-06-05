#include<LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);
int echo=2;
int trigger=3;
void setup() {
  lcd.begin(16,2);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);

}

void loop() {
 int t,d;
 digitalWrite(trigger,1);  
delayMicroseconds(10);
digitalWrite(trigger,0);
t=pulseIn(echo,1);
d=t*0.034/2;

lcd.clear();
lcd.setCursor(1,0);
lcd.print("distance in cm");
lcd.clear();
lcd.setCursor(1,1);
lcd.print(d);
lcd.setCursor(1,4);
lcd.print("cm");


}
