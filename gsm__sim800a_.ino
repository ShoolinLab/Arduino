
#include <SoftwareSerial.h>
SoftwareSerial gsm(9,10);
void setup() {
 Serial.begin(9600);
 gsm.begin(9600);}
void loop()
{ gsm.write("AT+CMGF=1\r\n");
     
  //delay(1000);  
  gsm.write("AT+CMGS=\"+918386827108\"\r"); // Replace x with mobile number
  delay(1000);
  gsm.write("ShoolinLab jaipur");// The SMS text you want to send
  delay(100);
  gsm.write((char)26);
  delay(1000);
  
}
