#pragma config(Sensor, dgtl3,  sonar,               sensorSONAR_raw)
#pragma config(Sensor, dgtl5,  leftEncoder,         sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  disableMotors,       sensorTouch)
#pragma config(Sensor, dgtl10, enableMotors,        sensorTouch)
#pragma config(Motor,  port1,           leftTop,       tmotorNormal, openLoop)
#pragma config(Motor,  port10,          rightTop,      tmotorNormal, openLoop, encoder, dgtl5)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool  bMotorsDisabled = true;
const int kDefaultBias = 937;

long  kPFactorAngle = 60;
long  kDFactorAngle = 100;
long  kIFactorAngle = 8;
long  kDividerAngle = 75;

long  kPFactorEncoder = 60; //60;
long  kDFactorEncoder = 80;
long  kDividerEncoder = 100; //200;

long  kMaxMotorPower = 127;
long  kMinMotorPower = 15;
const long kWeakPerformanceZone = 35;
bool  bFastCycles = true;

long   nLastSonar = 0;
long   nCurrSonar = 0;
long   nErrorAngle = 0;
long   nDerivativeAngle = 0;
long   nIntegralAngle = 0;
long   nLastErrorAngle = 0;

long   nBias = 0;
long   nErrorEncoder = 0;
long   nDerivativeEncoder = 0;
long   nLastErrorEncoder = 0;

long   nAccumulatedError[7] = {0, 0, 0, 0, 0, 0, 0};
long   nAdjustmentAngle;
long   nAdjustmentEncoder;
long   nAdjustment;
long   nSpeedLeft = 0;
long   nSpeedRight = 0;


long   nSonarDistance;
long   nSonarUpdateCycles = 0;

void leftMotor(long nSpeed)
{
  //motor[leftBottom] = nSpeed;
  if (bMotorsDisabled)
    motor[leftTop] = 0;
  else
    motor[leftTop] = nSpeed;
  nSpeedLeft = motor[leftTop];
}

void rightMotor(long nSpeed)
{
  //motor[rightBottom] = nSpeed;
  if (bMotorsDisabled)
    motor[rightTop] = 0;
  else
    motor[rightTop] = nSpeed;
  nSpeedRight = motor[rightTop];
}

task main()
{
  // Get Bias Value by Averaging 20 Samples

  if (false)
  {
    const long kBiasCounts = 100;

	  bFastSonarSensor = bFastCycles;
	  for (int nSamples = 0; nSamples < kBiasCounts; )
	  {
	    int nValue;

	    if (nSonarUpdateCycles == getSensorUpdateCycles(sonar))
	      continue;

	    nSonarUpdateCycles = getSensorUpdateCycles(sonar);
	    nValue = SensorValue[sonar];
	    if (nValue < 0)
	      continue;
	    nBias += nValue;
	    ++nSamples;
	  }
	  nBias /= kBiasCounts;
	}
	else
	  nBias = kDefaultBias;


  // Loop forever in a control loop adjusting motors to stay balanced

  SensorValue[leftEncoder] = 0;
  SensorValue[rightEncoder] = 0;
  nLastSonar = SensorValue[sonar];
  while (true)
  {
    bFastSonarSensor = bFastCycles;
    if (SensorValue[disableMotors])
    {
      bMotorsDisabled = true;
      if (SensorValue[enableMotors])
        nBias = SensorValue[sonar];
  }
  if (SensorValue[enableMotors])
      bMotorsDisabled = false;

    if (nSonarUpdateCycles == getSensorUpdateCycles(sonar))
      continue;
    nSonarUpdateCycles = getSensorUpdateCycles(sonar);

    nCurrSonar = SensorValue[sonar];
    nSonarDistance = SensorValue[sonar];
    if (nSonarDistance == -1)
      continue; // Out of range value

    nErrorEncoder = -(SensorValue[leftEncoder] + SensorValue[rightEncoder]) / 2;
    nDerivativeEncoder = nErrorEncoder - nLastErrorEncoder;
    nLastErrorEncoder = nErrorEncoder;
    //nIntegralEncoder += nErrorEncoder;

    nErrorAngle = nSonarDistance - nBias;
    nDerivativeAngle = nErrorAngle - nLastErrorAngle;
    nLastErrorAngle = nErrorAngle;
    nIntegralAngle += nErrorAngle;
    if (nIntegralAngle > 150)
      nIntegralAngle = 150;
    else if (nIntegralAngle < -150)
      nIntegralAngle = -150;
    nAccumulatedError[6] = nAccumulatedError[5];
    nAccumulatedError[5] = nAccumulatedError[4];
    nAccumulatedError[4] = nAccumulatedError[3];
    nAccumulatedError[3] = nAccumulatedError[2];
    nAccumulatedError[2] = nAccumulatedError[1];
    nAccumulatedError[1] = nAccumulatedError[0];
    nAccumulatedError[0] = nErrorAngle;
    nIntegralAngle = (nAccumulatedError[6] + nAccumulatedError[5] + nAccumulatedError[4] +
                nAccumulatedError[3] + nAccumulatedError[2] + nAccumulatedError[1]) / 6;

    nAdjustmentAngle  = (nErrorAngle * kPFactorAngle) + (nDerivativeAngle * kDFactorAngle) + (nIntegralAngle * kIFactorAngle);
    nAdjustmentAngle /= kDividerAngle;
    nAdjustmentEncoder = (nErrorEncoder * kPFactorEncoder) + (nDerivativeEncoder * kDFactorEncoder);
    nAdjustmentEncoder /= kDividerEncoder;

    nAdjustment = nAdjustmentAngle + nAdjustmentEncoder;
    if (nAdjustment > kMaxMotorPower)
      nAdjustment = kMaxMotorPower;
    else if (nAdjustment < -kMaxMotorPower)
      nAdjustment = -kMaxMotorPower;
    else if ((nAdjustment > -kMinMotorPower) && (nAdjustment < kMinMotorPower))
      nAdjustment = 0;

    if (nAdjustment > 0)
      nAdjustment += kWeakPerformanceZone;
    else if (nAdjustment < 0)
      nAdjustment -= kWeakPerformanceZone;

    leftMotor(nAdjustment);
    rightMotor(nAdjustment);
  }
}
