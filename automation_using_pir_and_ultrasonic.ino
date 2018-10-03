int echo1=6;
int trigger1=7;
int pir=5;
int buzzer=4;
int t1,d1;
int range=20;// you can change distance up to 400cm
int pirstate=0;
void setup() {

pinMode(buzzer,OUTPUT);
pinMode(trigger1,OUTPUT);
pinMode(echo1,INPUT);
pinMode(pir,INPUT);
}
int ultra()
{
digitalWrite(trigger1,1);
delayMicroseconds(10);
digitalWrite(trigger1,0);
t1=pulseIn(echo1,1);
d1=t1*0.034/2; 
return d1;
}

void loop() 
{
   pirstate=digitalRead(pir);
   int d=ultra();

if((d<=range)||(pir==LOW))
{
  digitalWrite(buzzer,0);
}
else if((d<=range)||(pir==HIGH))
{
  digitalWrite(buzzer,1);
}
}
