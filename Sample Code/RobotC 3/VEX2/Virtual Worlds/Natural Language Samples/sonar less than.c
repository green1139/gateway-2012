#pragma config(Sensor, in1,    lightSensor,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  compassSensor,       sensorVirtualCompass)
#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/****************************************\
|*  ROBOTC Virtual World                *|
|*  sonar less than (Natural Language)  *|
\****************************************/

// This program moves forward until the sonar sensor sees an object less than 40 units away.

task main()
{
  forward(75);                // move forward at speed 75
  untilSonarLessThan(40);     // continue until the sonar reads a value less than 40
  stop();                     // stop the robot
}
