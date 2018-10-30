#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

#define IR2 2
#define IR3 3
#define del 1000
#define led 13

int count=0;

void setup() {
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16,2);
}

void loop() {
  int bs2= digitalRead(IR2); 
  int bs3= digitalRead(IR3); 

  if(bs2==HIGH){
    count++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Person:");
    lcd.print(count);
    delay(del);
  }
  else if(bs3==HIGH){
    count--;
    lcd.clear();
    lcd.setCursor(0,0);  
    lcd.print("Person:");
    lcd.print(count);
    delay(del);
  }
    
  if(count==0){
    digitalWrite(led,LOW);
  }
  else{
    digitalWrite(led,HIGH);    
  }
}
