#pragma config(Sensor, in1,    lightSensor,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  compassSensor,       sensorVirtualCompass)
#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/**************************\
|*  ROBOTC Virtual World  *|
|*  Forward with Timing   *|
\**************************/

// This program moves forward for an amount of time.

task main()
{
                            // move forward:
  motor[rightMotor] = 75;   // set port2 to speed 75
  motor[leftMotor]  = 75;   // set port3 to speed 75

                            // continue movement:
  wait1Msec(2000);          // wait for 2000 milliseconds (2 seconds)

                            // stop the robot:
  motor[rightMotor] = 0;    // set port2 to speed 0
  motor[leftMotor]  = 0;    // set port3 to speed 0
}
