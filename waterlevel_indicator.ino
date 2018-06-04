

void setup() {
  
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
    

}

void loop() {
int level1=digitalRead(2);
int level2=digitalRead(3);
int level3=digitalRead(4);
if(level1==0 & level2==0 & level3==0)
  {
    digitalWrite(11,0);
    digitalWrite(12,0);
    digitalWrite(13,0);
    
  }
if(level1==1 & level2==0 & level3==0)
  {
    digitalWrite(11,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    
  }
  
  if(level1==1 & level2==1 & level3==0)
  {
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(13,0);
  }

  if(level1==1 & level2==1 & level3==1)
  {
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(13,1);
  }
  
}
