#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void)
{
Serial.begin(9600);
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
Serial.print(int(accelEvent.acceleration.y));
Serial.print(int(accelEvent.acceleration.z));
delay(1000); 
int data1=accelEvent.acceleration.x;
int data2=accelEvent.acceleration.y;
int data3=accelEvent.acceleration.z;
if((data1==0)&&(data2==-11)&&(data3==1))
{
  Serial.print("1condition");
}
if((data1==2)&&(data2==1)&&(data3==-7))
{
  Serial.print("2condition");
}
if((data1==-9)&&(data2==0)&&(data3==2))
{
  Serial.print("3condition");
}
if((data1==10)&&(data2==0)&&(data3==0))
{
  Serial.print("4condition");
}
}

