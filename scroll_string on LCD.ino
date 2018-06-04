#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
void setup()
{  lcd.begin(16,2);

}

void loop() {
 int a;
 int b;
 int i;

for(i=0; i<=60; i++)
 {
  for(a=0; a<=60; a++)
  {
   for(b=0; b<=60; b++)
   {
    lcd.setCursor(1,0);
    lcd.print(i);
    lcd.setCursor(4,0);
    lcd.print(a);
   lcd.setCursor(8,0);
    lcd.print(b);
    delay(100);
    
   }
  }
  

 }
 
}
