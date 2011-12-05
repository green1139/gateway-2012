#pragma config(Sensor, in1,    lightSensor,         sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  compassSensor,       sensorVirtualCompass)
#pragma config(Sensor, dgtl6,  touchSensor,         sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,         sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Moving Forward
This program instructs your robot to move forward at full power for three seconds.
There is a two second pause at the beginning of the program.

Robot Model(s): Squarebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor

*To run this sample program on Swervebot, be sure to Reverse Motor Port 3 in the Motors and Sensors
 Setup, and to make sure that Motor Port 2 is NOT Reversed.
----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);						// Robot waits for 2000 milliseconds before executing program

	// Move forward at full power for 3 seconds
	motor[rightMotor] = 127;		  // Motor on port2 is run at full (127) power forward
	motor[leftMotor]  = 127;		  // Motor on port3 is run at full (127) power forward
	wait1Msec(3000);			        // Robot runs previous code for 3000 milliseconds before moving on
}												        // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
