#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  mySerial.println("AT+CMGF=1"); 
  delay(1000);
}


void loop()
{
  if(mySerial.available()>0)
  {
    Serial.print("ddff");
    String data=mySerial.readString();
    Serial.print(data);
  }
}

  
