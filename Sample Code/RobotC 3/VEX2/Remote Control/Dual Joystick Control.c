#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                    - Dual Joystick Control -                                      *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses a both the Left and the Right joysticks to run the robot using "tank control".  *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 3          leftMotor            VEX Motor           Left motor                     *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{

  while(1 == 1)
  {
    motor[leftMotor]  = vexRT[Ch3];   // Left Joystick Y value
    motor[rightMotor] = vexRT[Ch2];   // Right Joystick Y value
  }

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
