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
Turning with Compass
This program instructs your robot turn until the desired number of degrees has been reached.
There is a two second pause at the beginning of the program.

Robot Model(s): Squarebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor
Digital Port 5      compassSensor       Compass

*To run this sample program on Swervebot, be sure to Reverse Motor Port 3 in the Motors and Sensors
 Setup, and to make sure that Motor Port 2 is NOT Reversed.
----------------------------------------------------------------------------------------------------*/

// This program turns right for a specified 'degrees'

task main()
{
  wait1Msec(2000);
  int degrees = 90;                     // 'degrees' is how many degrees we want to turn

  int goal = (SensorValue[compassSensor] + degrees) % 360;  // 'goal' is be the current compassSensor reading + our turning degrees
                                                      /* We have to use modulus 360 to keep our goal within the bounds   */
                                                      /* of the compassSensor (1 to 360 degrees, 0 is 360).                    */

  while(SensorValue[compassSensor] != goal)   // while the compassSensor sensor reading is not yet our goal:
  {
										// turn RIGHT in place (point turn):
    motor[rightMotor] = -15;           	// set port2 to speed -15
    motor[leftMotor]  = 15;            	// set port3 to speed 15
  }
                                        // stop the robot:
  motor[rightMotor] = 0;                // set port2 to speed 0
  motor[leftMotor]  = 0;                // set port3 to speed 0
}
