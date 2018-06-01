int c=0;
void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  c = digitalRead(5);

}
void forward()
{
   
    digitalWrite(1,0);
    digitalWrite(2,1);
    digitalWrite(3,0);
    digitalWrite(4,1);
  
}

 void tostop()
  {
    digitalWrite(1,0);
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
  }
  
void loop() {
 c = digitalRead(5);
if(c==0)
{
  forward();
}
else if(c==1)
{
  tostop();
}
 
  }


