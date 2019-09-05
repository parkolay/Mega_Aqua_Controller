/*  This sketch sets up a small OLED display and pulls analog signals from 
 *   MQ135(air quality --> SnO2 detects CO2 && VOC))
 * 
 *  Requirements:
 *
 *  * Nano or other Arduino board
 *  * Arduino 1.8.8+ IDE
 *  * Library: U8g2lib.h --> u8g2 by oliver was used
 *
 * 
 * 
 *  // Pinout                   Nano  Mega
 *  //  MQ135 analog Output --> A00   A00
 *  //  SCL                 --> A04    21
 *  //  SDA                 --> A05    20
 *  
 *   
 *   
 *   
 *   
 *   Created: Aug 30, 2019 by Dan Parkolay (with a lot of help from a lot of other people)
*/

#include <Arduino.h>
#include <U8g2lib.h>
#include "SparkFunBME280.h"
#include "RTClib.h"
#include <L293.h>

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

//Setup Moisture input pins
const int Moisture1 = A1;

const int Moisture2 = A2;
float Moisture1Value = 0;
float MoistureLimit1 = 4.0;
float Moisture2Value = 0;
float MoistureLimit2 = 4.0;

// give a name to the motor driver pins that are used
const int speedPin1 = 2;    // that is the pin that we use to control the motor's speed
const int forwardPin1 = 3; // this is the pin that we use to tell the motor to go forward
const int reversePin1 = 4; // this is the pin that we use to tell the motor to go reverse
const int speedPin2 = 5;    // that is the pin that we use to control the motor's speed
const int forwardPin2 = 6; // this is the pin that we use to tell the motor to go forward
const int reversePin2 = 7; // this is the pin that we use to tell the motor to go reverse


L293 motor1( speedPin1, forwardPin1, reversePin1 );
L293 motor2( speedPin2, forwardPin2, reversePin2 );

//Initialize BME280
BME280 bme280;

//Initialize SSD1306 Display
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//Initialize RTC
DS3231 rtc;

void setup(void) 
{
  Wire.begin();
  Serial.begin(57600);
  Serial.println("initializing...");

  SetupRTC();     //Initialize the RTC
  SetupBME280();  //Initialize the temp, rH and pressure sensor
  
  u8g2.begin();   //Initialize the OLED display
    // connect AREF to 3.3V and use that as VCC, less noisy!  
    //thank you for the tip Lady Ada
  analogReference(EXTERNAL);  

}

void loop(void) 
{

  UpdateMQ135();
  DebugBMEData();
  UpdateRTC();
  UpdateMoistureInputs();


  delay(100);
  u8g2.firstPage();
  do 
  {

    UpdateDisplay();
//    UpdatePumps();
  } 
  while ( u8g2.nextPage() );
  //delay(1000);
    UpdatePumps();
}
