void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT); 
  pinMode(4,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() 
{
  int low=digitalRead(2);
int medium=digitalRead(3);
int full=digitalRead(4);
if(low==1 & medium==0 & full==0)
  {
    digitalWrite(8,1);
     digitalWrite(9,0);
  digitalWrite(10,0);
    
  }
  if(medium==1 & low==1 & full==0)
{
  digitalWrite(8,1);
  digitalWrite(9,1);
  digitalWrite(10,0);
}
   if(full==1 & medium==1 & low==1)
  {
  digitalWrite(8,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  }
  if(full==0 & medium==0 & low==0)
  {
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  }

}
