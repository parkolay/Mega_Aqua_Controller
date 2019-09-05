void UpdatePumps()
{
  //motor1.forward(255); // set the direction and the speed of the motor
  if (Moisture1Value >= MoistureLimit1)  //is the moisture sensor is reading less than 4 volts run the pump
  {
      motor1.forward(255);
      Serial.print(Moisture1Value);
      Serial.print(" motor 1 running ");
      Serial.println(MoistureLimit1);
  }
  
  else if (Moisture1Value < MoistureLimit1) 
  {
      motor1.forward(0);
      Serial.print(Moisture1Value);
      Serial.print(" motor 1 stopped ");
      Serial.println(MoistureLimit1);
  }
  
  if (Moisture2Value >= MoistureLimit2)  //is the moisture sensor is reading less than 4 volts run the pump
  {
      motor2.forward(255);
      Serial.print(Moisture2Value);
      Serial.print(" motor 2 running ");
      Serial.println(MoistureLimit2);
  }
    else if (Moisture2Value < MoistureLimit2) 
  {
      motor2.forward(0);
      Serial.print(Moisture2Value);
      Serial.print(" motor 2 stopped ");
      Serial.println(MoistureLimit2);
  }

  //delay( 1000 );        // wait for 1 second before doing else
//  motor.back( 255 );    // set a new direction and the speed of the motor
//  delay( 1000 );        // wait for 1 second before doing else
//  motor.stop();         // stop the motor
//  delay( 1000 );        // wait for 1 second before doing else
}
