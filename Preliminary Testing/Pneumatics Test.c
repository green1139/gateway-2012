#pragma config(Sensor, dgtl6,  solenoid,            sensorDigitalOut)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  while(true)                     // Loop Forever
  {
      wait1Msec(2000);
      SensorValue[solenoid] = 1;  // ...activate the solenoid.
wait1Msec(2000);
      SensorValue[solenoid] = 0;  // ..deactivate the solenoid.

  }
}
