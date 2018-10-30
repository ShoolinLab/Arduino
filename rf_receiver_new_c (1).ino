#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
int in1=2;
int in2=3;
int in3=4;
int in4=5;
String condition1="Hello1world";
String condition2="Hello2world";
String condition3="Hello3world";
String condition4="Hello4world";
String condition5="Hello5world";
RH_ASK driver;

void setup()
{   pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);  
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
void forward()
{
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  Serial.print("forward");
}
void backward()
{
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  Serial.print("backward");
}
void ruk()
{
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
  Serial.print("ruk");
}
void right()
{
 digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0); 
  Serial.print("right");
}
void left()
{
 digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0); 
  Serial.print("left");
}
void loop()
{
    uint8_t buf[10];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      // Message with a good checksum received, dump it.
      //Serial.print("Message: ");
     // Serial.println((char*)buf);
      String data=buf;
      Serial.print(data);
      Serial.println(".......");
      String altr = data.substring(0,6);

      if(altr==condition1){
        Serial.print("Hello1world");
        forward();
      }
      else if(altr==condition2){
        Serial.print("Hello2world");
        backward();
      }
      else if(altr==condition3){
        Serial.print("Hello3world");
        right();
      }
      else if(altr==condition4){
        Serial.print("Hello4world");
        left();
      }
       else 
       {
        ruk();
      }
    
    }
}
