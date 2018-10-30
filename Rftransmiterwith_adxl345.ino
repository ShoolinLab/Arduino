#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void)
{
  Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
//Serial.begin(9600);
Serial.println("ADXL345 Accelerometer Calibration");
Serial.println("");
/* Initialise the sensor */
if(!accel.begin())
{
/* There was a problem detecting the ADXL345 ... check your connections */
Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
while(1);
}
}
void loop(void)
{
 
Serial.println("ready");
delay(1000);

sensors_event_t accelEvent;
accel.getEvent(&accelEvent);
Serial.print(int(accelEvent.acceleration.x));
Serial.print("  ");
Serial.print(int(accelEvent.acceleration.y));
Serial.print("  ");
Serial.print(int(accelEvent.acceleration.z));
Serial.print("  ");
delay(1000); 
int data1=accelEvent.acceleration.x;
int data2=accelEvent.acceleration.y;
int data3=accelEvent.acceleration.z;
if((data1==0)&&(data2==-1)&&(data3==11))
{
  Serial.print("Left");
   const char *msg = "Hello1world";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
if((data1==0)&&(data2==1)&&(data3==-8))
{
  Serial.print("Backward");
   const char *msg = "Hello2world";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
if((data1==-9)&&(data2==0)&&(data3==0))
{
  Serial.print("stop");
   const char *msg = "Hello3world";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
if((data1==10)&&(data2==0)&&(data3==1))
{
  Serial.print("Hello4world");
   const char *msg = "Hello4world";
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
}
}
