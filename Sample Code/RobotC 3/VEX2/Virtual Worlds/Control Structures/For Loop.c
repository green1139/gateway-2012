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
For Loop

This program uses a "for" loop to instruct the robot to traverse a square 5 times by repeating moving
forward and turning behaviors 20 times. There is a two second pause at the beginning of the program.

A "for" loop is more condensed than a "while" loop; it declares and initializes the variable,
makes a comparison for the condition, and increments the variable all in the first line (declaration).

The integer variable 'i' is needed to keep track of the number of times that the "for" loop has run.

Robot Model(s): Squarebot & Swervebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor

*To run this sample program on Swervebot, be sure to Reverse Motor Port 3 in the Motors and Sensors
 Setup, and to make sure that Motor Port 2 is NOT Reversed.
----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);						      // Robot waits for 2000 milliseconds before executing program

	for(int i = 0; i < 20; i++)   /* This for() loop:  declares the integer 'i' and initializes it to 0,                           */
	{                             /* repeats the code as long as 'i' is less than 20, and increments 'i' by 1 after each iteration */

		// Move forward at half power for 2 seconds
		motor[rightMotor] = 63;			    // Motor on port2 is run at half (63) power forward
		motor[leftMotor]  = 63;			    // Motor on port3 is run at half (63) power forward
		wait1Msec(2000);				        // Robot runs previous code for 2000 milliseconds before moving on

		// Turn Left at half power for 0.5 seconds
		motor[rightMotor] = 63;     	  // Motor on port2 is run at half (63) power forward
		motor[leftMotor]  = -63;    	  // Motor on port3 is run at half (-63) power reverse
		wait1Msec(500);        	        // Robot runs previous code for 500 milliseconds before moving on

	}

}														        // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
