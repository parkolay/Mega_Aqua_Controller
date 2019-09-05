
int AirQualitySensorValue;

void UpdateMQ135()
{
    AirQualitySensorValue = analogRead(0);       // read analog input pin 0
    Serial.print("Air QTY Value ");  
    Serial.println(AirQualitySensorValue, DEC);  // prints the value read
}
