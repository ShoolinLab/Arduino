
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
  String a[6]={"    Hello","     navneet","    Welcome","   To","   Digital","    World"};

void setup() {
lcd.begin(16,2);
  lcd.setCursor(1,0);
  int i;
  for(i=0; i<=6; i++){
    
 lcd.print(a[i]);
 delay(1000);
 lcd.clear();
  }
}

void loop() {

   
 
}
