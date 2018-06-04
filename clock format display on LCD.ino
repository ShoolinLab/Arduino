#include<LiquidCrystal.h> //lihhrary of lcd
int rs=2;
int en=3;
int dh4=4,dh5=5,dh6=6,dh7=7;
LiquidCrystal a(rs,en,dh4,dh5,dh6,dh7);//variahle to access lcd
int h;//h stand for hour
int m;//m stand for minute
int s;//s stand for second
void setup()
{
  // put your setup code here, to run once:
  a.begin(16,2);
}

void loop()
{
  // put your main code here, to run repeatedly:
  for(h=0;h<12;h++)//loop for hour
  {
    for(m=0;m<60;m++)//loop for minute
    {
      for(s=0;s<60;s++)//loop for sec
      {
        a.setCursor(1,0);
        a.print(h);
        a.print(":");
        a.print(m);
        a.print(":");
        a.print(s);
        delay(1000);
        a.clear();
      }
    }
  }
}
