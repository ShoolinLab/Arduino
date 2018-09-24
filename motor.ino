int in1=2;
int in2=3;
int in3=4;
int in4=5;
int button1=6;
int button2=7;
int buttonstate1=0;
int buttonstate2=0;
void setup()
 {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT); 
 }
 void forward()
 {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 }
 void backward()
 {
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
 }
 void stop1()
 {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,1);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,1);
 }
 void loop()
 {
  buttonstate1=digitalRead(button1);
  buttonstate2=digitalRead(button2);
  if(buttonstate1==HIGH)
  {
    forward();
  }
  else if(buttonstate2==HIGH)
  {
    backward();
  }
  else if(buttonstate1==LOW&&buttonstate2==LOW)
  {
    stop1();
  }
 }
  



