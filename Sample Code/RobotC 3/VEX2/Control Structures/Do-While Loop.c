#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


/*----------------------------------------------------------------------------------------------------*\
|*                                         - Do-While Loop -                                          *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses a "do-while" loop to instruct your robot to traverse a square 5 times by        *|
|*  repeating moving forward and turning behaviors 20 times.                                          *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  When using "do-while" loops, the code between its braces is always run at least once,       *|
|*        since the condition is not checked until after it is run.                                   *|
|*    3)  The integer variable 'i' is needed to keep track of the number of times that the            *|
|*        "do-while" loop has run.                                                                    *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(2000);						          // Robot waits for 2000 milliseconds before executing program

	int i = 0;									          // Declares integer variable 'i' and initializes it to 0

	do	// Using "do" guarantees the code will be run at least once since the condition is checked after each iteration, not before
	{

		// Move forward at half power for 2 seconds
		motor[rightMotor] = 63;			        // Motor on port2 is run at half (63) power forward
		motor[leftMotor]  = 63;			        // Motor on port3 is run at half (63) power forward
		wait1Msec(2000);				            // Robot runs previous code for 2000 milliseconds before moving on

		// Turn Left at half power for 0.5 seconds
		motor[rightMotor] = 63;     	      // Motor on port2 is run at half (63) power forward
		motor[leftMotor]  = -63;    	      // Motor on port3 is run at half (-63) power reverse
		wait1Msec(500);        	            // Robot runs previous code for 500 milliseconds before moving on

		i++;										            // increment i by 1 (same as "i = i + 1")

	}
	while(i < 20);	// This do-while() loop repeats the code above while 'i' is less than 20

}														            // Program ends, and the robot stops
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
