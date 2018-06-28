//int LED = 4;
int motor = 13;
int temp = 0;
int i = 0;
char str[15];
boolean gotGPS = false;
#include <SoftwareSerial.h>
#include <TinyGPS.h>
long lat, lon; // create variable for latitude and longitude object
SoftwareSerial GPS(2, 3); // create gps sensor connection
TinyGPS gps; // create gps object
void setup()
{
  Serial.begin(9600);
  GPS.begin(9600);
  pinMode(motor, OUTPUT);


  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(500);

}
void loop()
{
  if (temp == 1)
  {
    check();
    temp = 0;
    i = 0;
    delay(1000);
  }
}
void serialEvent()
{
  while (Serial.available())
  {
    if (Serial.find("/"))
    {
      delay(1000);
      while (Serial.available())
      {
        char inChar = Serial.read();
        str[i++] = inChar;
        if (inChar == '/')
        {
          temp = 1;
          return;
        }
      }
    }
  }
}
void check()
{
  if (!(strncmp(str, "Motor on", 8)))
  {
    digitalWrite(motor, HIGH);
   // digitalWrite(LED, HIGH);
    delay(1000);
    Serial.println("AT+CMGS=\"+917732904500\"\r"); // Replace x with mobile number
    
    delay(1000);
    Serial.println("Motor Activated");// The SMS text you want to send
    delay(100);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
  else if (!(strncmp(str, "Motor off", 9)))
  {
    digitalWrite(motor, LOW);
    //digitalWrite(LED, 0);
    delay(1000);
  /*  Serial.println("AT+CMGS=\"+918386827108\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.println("Motor deactivated");// The SMS text you want to send
    delay(100);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);*/
    while (!gotGPS) {
      byte a;

      if (GPS.available())
      {

        a = GPS.read();
        //Serial.println(String(a));
        //Serial.write(a);  uncomment this line to get NMEA data on Serial window
        while (gps.encode(a))
        {
          gps.get_position(&lat, &lon);

          Serial.println("AT+CMGS=\"+917732904500\"\r");
          
          delay(1000);
          Serial.print("Position: ");
          delay(1000);
         // Serial.print("\n ");
          Serial.print("lat ");
          Serial.print((lat * 0.000001), 8);
          Serial.print(", ");
          Serial.print("lon ");
          Serial.println((lon * 0.000001), 8);
         // Serial.print("\n");
          Serial.println((char)26);
          gotGPS = true;

        }
      }


    }
    gotGPS = false;

  }
  else if (!(strncmp(str, "test", 4)))
  {
    Serial.println("AT+CMGS=\"+918625076864\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.println("The System is Working Fine.");// The SMS text you want to send
    delay(100);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
}
