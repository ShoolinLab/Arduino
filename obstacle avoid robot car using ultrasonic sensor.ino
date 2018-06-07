int echo1=6;
int trigger1=7;
int echo2=8;
int trigger2=9;
int echo3=10;
int trigger3=11;
int echo4=12;
int trigger4=13;
int t1,t2,t3,t4,d1,d2,d3,d4;

void setup() {

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(trigger1,OUTPUT);
pinMode(trigger2,OUTPUT);
pinMode(trigger3,OUTPUT);
pinMode(trigger4,OUTPUT);
pinMode(echo1,INPUT);
pinMode(echo2,INPUT);
pinMode(echo3,INPUT);
pinMode(echo4,INPUT);
}

void loop() {
digitalWrite(trigger1,1);
delayMicroseconds(10);
digitalWrite(trigger1,0);
t1=pulseIn(echo1,1);
d1=t1*0.034/2;
if(d1<=20)
{
  digitalWrite(2,0);
  digitalWrite(3,1);
  digitalWrite(4,0);
  digitalWrite(5,1);
}
digitalWrite(trigger2,1);
delayMicroseconds(10);
digitalWrite(trigger2,0);
t2=pulseIn(echo2,1);
d2=t2*0.034/2;
if(d2<=20)
{
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
}
digitalWrite(trigger3,1);
delayMicroseconds(10);
digitalWrite(trigger3,0);
t3=pulseIn(echo3,1);
d3=t3*0.034/2;
if(d3<=20)
{
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,0);
}
digitalWrite(trigger4,1);
delayMicroseconds(10);
digitalWrite(trigger4,0);
t4=pulseIn(echo4,1);
d4=t4*0.034/2;
if(d4<=20)
{
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
}
}
