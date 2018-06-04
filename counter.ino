#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int st = 0;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(8, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  st = digitalRead(8);
  if (st == 1)
  {
    count = count + 1;
    lcd.setCursor(1, 0);
    lcd.print(count);
    lcd.clear();
  }
}
