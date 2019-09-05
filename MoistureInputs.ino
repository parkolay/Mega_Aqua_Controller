void UpdateMoistureInputs()
{
  // read the value from the sensor:
//  const int Moisture1 = A1;
//  const int Moisture2 = A2;
  Moisture1Value = analogRead(Moisture1) ;
  Moisture1Value = (Moisture1Value *(5.0/1023));//adjust to voltage
  Moisture2Value = analogRead(Moisture2);
  Moisture2Value = (Moisture2Value *(5.0/1023));//adjust to voltage
}
