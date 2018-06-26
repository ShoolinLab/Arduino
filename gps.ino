
long lat, lon;
boolean gotGPS;

#include <SoftwareSerial.h>
#include <TinyGPS.h>

SoftwareSerial GPS(4, 5); // create gps sensor connection
TinyGPS gps;
void setup()
{
  Serial.begin(9600);
  GPS.begin(9600);
}
void loop()
{
  

      byte a;

      if (GPS.available())
      {

        a = GPS.read();
        while (gps.encode(a))
        {
          gps.get_position(&lat, &lon);
          Serial.print("Position: ");
          Serial.print("\n ");
          Serial.print("lat ");
          Serial.print((lat * 0.000001), 8);
          Serial.print(", ");
          Serial.print("lon ");
          Serial.println((lon * 0.000001), 8);
          Serial.print("\n");
         
  

      }}}
