#pragma config(Sensor, in1,    lightSensor,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  compassSensor,       sensorVirtualCompass)
#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/********************************************\
|*  ROBOTC Virtual World                    *|
|*  turning with compass (Natural Language) *|
\********************************************/

// This program makes a 90 degree point turn left.
// Notice the buffer that we pass to 'untilCompassDegrees'.
// Without it, your robot needs to hit the EXACT degree, which is not always the case.
// If you speed your robot up, or if your computer isn't too fast, increase the buffer size!

task main()
{
  int degrees = 90;                   	// 'degrees' is how many degrees we want to turn
  int buffer = 2;                     	// 'buffer' is how many degrees + or - from our goal we can accept
  pointTurn(left, 10);                	// make a left point turn at speed 10
  untilCompassDegrees(degrees, buffer); // contine until the compass sensor reaches 'degrees', + or - buffer
  stop();                             	// stop
}
