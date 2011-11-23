#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                 - ADVANCED Movement by Rotation -                                  *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses functions 'TurnLeft(float)' and 'Forward(float)' to very neatly and modularly   *|
|*  run your robot in a square.  There is a two second pause at the beginning of the program.         *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" model, but may not be needed for all robot configurations.                      *|
|*    2)  The values that you pass to the functions, 'Forward(float)' and 'TurnLeft(float)' are then  *|
|*        given to 'r' in each function.                                                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor   - Port 2    rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor   - Port 3    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital - Port 1,2  rightEncoder        VEX Quadrature enc.   Right side encoder                *|
|*    Digital - Port 3,4  leftEncoder         VEX Quadrature enc.   Left side encoder                 *|
\*-----------------------------------------------------------------------------------------------4246-*/

// Functions Prototypes
void Forward(float r);
void TurnLeft(float r);

// Declare Global Variables     /* 'rotations' will be a counter for every 360 encoder clicks */
const float rotations = 360.0;  /* which is one full rotation of the wheel (ie. 2 'rotations' */
                                /* will equal 720.0 clicks, 2 full rotations of the wheel).   */


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);        // Wait 2000 milliseconds before continuing.

  int i;
  for(i=0; i<4; i++)      // While 'i' is less than 4:
  {
    Forward(3.0);         // Call function 'Forward(float)' and pass the float value '3.0' through.
    TurnLeft(1.3);        // Call function 'TurnLeft(float)' and pass the float value '1.3' through.
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------------| FORWARD |---------------------------------------------
void Forward(float r)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */

  // While the encoders have not yet met their goal: (r * rotations) ie (3.0 * 360.0) or "three rotations"
  while(SensorValue[rightEncoder] < (r * rotations) && SensorValue[leftEncoder] < (r * rotations))
  {
    motor[rightMotor] = 63;         /* Run both motors        */
    motor[leftMotor]  = 63;         /* forward at half speed. */
  }
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| TURN LEFT |--------------------------------------------
void TurnLeft(float r)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */

  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)
  while(SensorValue[rightEncoder] < (r * rotations) && SensorValue[leftEncoder] > (-1 * r * rotations))
  {
    motor[rightMotor] = 63;         // Run the right motor forward at half speed
    motor[leftMotor]  = -63;        // Run the left motor backward at half speed
  }
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
//----------------------------------------------------------------------------------------------------
