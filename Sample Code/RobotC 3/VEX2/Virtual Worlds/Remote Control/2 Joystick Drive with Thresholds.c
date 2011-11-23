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
2 Joystick Drive with Thresholds
- This program instructs allows you to remotely control your robot using the USB Logitech Dual
  Action Joysticks.
- This program also ignores low values that would cause your robot to move when the joysticks fail to
  return back to exact center.  You may need to adjust the 'threshold' value to get it just right.
- For USB values to be transmitted to the robot, you must follow several steps:
  - Use the "#include "JoystickDriver.c"" line at the beginning of your program
  - Call the "getJoystickSettings(joystick);" in a loop to repeatedly retrieve the latest values
  - Open the Robot > Debugger Windows > "Joystick Control - Basic" window after downloading your
    program to the virtual robot

Robot Model(s): Squarebot

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        rightMotor          VEX Motor             Right side motor
Motor Port 3        leftMotor           VEX Motor             Left side motor

*To run this sample program on Swervebot, be sure to Reverse Motor Port 3 in the Motors and Sensors
 Setup, and to make sure that Motor Port 2 is NOT Reversed.
----------------------------------------------------------------------------------------------------*/

#include "JoystickDriver.c"

task main()
{
  //Integer variable that allows you to specify a "deadzone" where values (both positive or negative)
  //less than the threshold will be ignored.
  int threshold = 10;

  //Loop Forever
  while(1 == 1)
  {
    //Get the Latest joystick values
    getJoystickSettings(joystick);
    if(abs(joystick.joy1_y2) > threshold)     // If the right analog stick's Y-axis readings are either above or below the threshold...
    {
      motor[rightMotor] = joystick.joy1_y2;   // ...the right motor is assigned a power level equal to the right analog stick's Y-axis reading.
    }
    else                                      // Else the readings are within the threshold, so
    {
      motor[rightMotor] = 0;                  // ...the right motor is stopped with a power level of 0.
    }


    if(abs(joystick.joy1_y1) > threshold)     // If the left analog stick's Y-axis readings are either above or below the threshold...
    {
      motor[leftMotor] = joystick.joy1_y1;    // ...the left motor is assigned a power level equal to the left analog stick's Y-axis reading.
    }
    else                                      // Else if the readings are within the threshold...
    {
      motor[leftMotor] = 0;                   // ...the left motor is stopped with a power level of 0.
    }
  }
}
