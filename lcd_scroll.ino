#include<LiquidCrystal.h>
LiquidCrystal lcd (2,3,4,5,6,7);
void setup() {

  lcd.begin(16,2);

}

void loop() {
  
for(int i=0;i<=16;i++)
{
    lcd.clear();
  lcd.setCursor(i,0);
  lcd.print("Hello");
delay(50);
}
for(int i=16;i>=0;i--)
{
    lcd.clear();
  lcd.setCursor(i,1);
  lcd.print("World");
delay(50);
}
  

}
