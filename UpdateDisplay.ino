/*
 
  U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2
  make -f Makefile.184.uno
  
   text     
   8732               default, all active
   8500     -232      -2.65%    no U8G2_WITH_CLIP_WINDOW_SUPPORT
   8316     -416      -4.76%    no U8G2_WITH_FONT_ROTATION
   8606     -126      -1.44%    no U8G2_WITH_UNICODE
   8692     -40       -0.45%    no U8G2_WITH_INTERSECTION
   8328     -404      -4.62%    no U8G2_WITH_INTERSECTION  no U8G2_WITH_CLIP_WINDOW_SUPPORT
   8718     -14       -4.86%    no U8G2_WITH_HVLINE_SPEED_OPTIMIZATION
   8026     -706      -8.08%    no U8G2_WITH_FONT_ROTATION   no U8G2_WITH_INTERSECTION  no U8G2_WITH_CLIP_WINDOW_SUPPORT
   
   Some flags depend on each other: `U8G2_WITH_INTERSECTION` is required for `U8G2_WITH_CLIP_WINDOW_SUPPORT`, so `U8G2_WITH_INTERSECTION` is partly active as long
   as `U8G2_WITH_CLIP_WINDOW_SUPPORT` is requested.
   
*/
/*
  U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

void UpdateDisplay()
{
  GetLine1();
  GetLine2();
  GetLine3();
  GetLine4();
  GetLine5();
  GetLine6();
}

void GetLine1()
{
    DateTime now = rtc.now();
    char buf[100];                           //buffer for the RTC TimeDate Stamp
    strncpy(buf,"DD.MM.YY  hh:mm:ss\0",100);
    // u8g2.setCursor(0,13);                //This sets the bottom of the Yellow section of display
    u8g2.setCursor(0,8);
    //u8g2.setFont(u8g2_font_ncenB12_tr);   //This font fills the whole top yellow section of the screen
    u8g2.setFont(u8g2_font_ncenB08_tr);
    //u8g2.drawStr(0,13,"AirQltySensor");   //Left this format for reference
    u8g2.print("     ");
    u8g2.print(now.format(buf));
    //Serial.println(now.format(buf));
    //Serial.println("Display Line 1 Updated");
}

void GetLine2()
{
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(0,24);
    u8g2.print(AirQualitySensorValue);
    u8g2.print("  ");
//    u8g2.print(samples[1]); 
    u8g2.setCursor(64,24);
    u8g2.print(bme280.readTempF());
    u8g2.print("f ");
    //Serial.println("Display Line 2 Updated");
}

void GetLine3()
{
    u8g2.setCursor(0,34);
    u8g2.print(Moisture1Value);
//    //u8g2.setCursor(30,34);
//    u8g2.print(" *C --> ");
    u8g2.setCursor(64,34);
    u8g2.print(Moisture2Value);
//    //u8g2.setCursor(68,34);
//    u8g2.print(" *f ");
    //u8g2.print("012345678901234567890"); 
    //Serial.println("Display Line 3 Updated");
    
}

void GetLine4()
{
    u8g2.setCursor(0,44);
    u8g2.print(bme280.readFloatHumidity());
    u8g2.print("%Rh ");
    u8g2.setCursor(64,44);
    u8g2.print(bme280.dewPointF());
    u8g2.print("dp");
    //u8g2.print("012345678901234567890"); 
    //Serial.println("Display Line 4 Updated");
}

void GetLine5()
{
    u8g2.setCursor(0,54);
    u8g2.print(bme280.readFloatAltitudeFeet());
    u8g2.print("ft ");
    u8g2.setCursor(64,54);
    u8g2.print((bme280.readFloatPressure())/1000);
    u8g2.print("kpa"); 
    //u8g2.print("012345678901234567890"); 
    //Serial.println("Display Line 5 Updated");
}

void GetLine6()
{
//    u8g2.setCursor(0,64);
//    u8g2.print(RHRawSensorValue);
//    //u8g2.setCursor(25,64);
//    u8g2.print("Tks ");
//    //u8g2.setCursor(43,64);
//    u8g2.print(RHSensorValue);
//   // u8g2.setCursor(64,64);
//    u8g2.print("V ");
//    //u8g2.setCursor(72,64); 
//    u8g2.print(RHValue); 
//    //u8g2.setCursor(96,64); 
//    u8g2.print("%RH"); 
    //Serial.println("Display Line 6 Updated");
}
