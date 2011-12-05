#pragma config(UART_Usage, UART1, VEX_2x16_LCD, baudRate1200, IOPins, None, None)
#pragma config(Sensor, in4,    ,                    sensorLineFollower)
#pragma config(Sensor, dgtl1,  left,                sensorTouch)
#pragma config(Sensor, dgtl2,  middle,              sensorTouch)
#pragma config(Sensor, dgtl3,  right,               sensorTouch)
#pragma config(Sensor, dgtl4,  ,                    sensorTouch)
#pragma config(Sensor, dgtl5,  ,                    sensorTouch)
#pragma config(Sensor, dgtl6,  ,                    sensorTouch)
#pragma config(Sensor, dgtl7,  ,                    sensorTouch)
#pragma config(Sensor, dgtl8,  ,                    sensorTouch)
#pragma config(Sensor, dgtl9,  ,                    sensorTouch)
#pragma config(Sensor, dgtl10, ,                    sensorSONAR_cm)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                             Test Execution Speed
//
// This program is used to test the execution speed of the NXT brick.
//
// The basic methodology is to:
//  [1] measure the time to loop 10,000 times through an empty 'for' loop.
//  [2] measure the time to loop 10,000 times through an 'for' loop containing
//      10 identical statements.
//  [3] Take the time difference between the two loops to find the time to
//      execute 100,000 statements.
//  [4] Interpret to determine the number of microseconds per statement.
//
// To see the results of this test you should have the "Global Variables" debugger window open.
// The array 'nElapsedTime' will show the time taken to execute in microseconds a selection of
// different ROBOTC opcodes.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma platform(VEX2)

const int kNumberOfLoops = 10000; // 10K x 10 instructions per loop = 100K instructions

#define testSensorType sensorTouch

#undef useLongs
#undef useFloats
#define useLongs
#define useFloats

	const TTimers  executionTimer = T1;

typedef enum
{
	typeIdleLoop,
	typeAlive,

	typeIntegerAssignConstant,
	typeIntegerAddConstant,
	typeIntegerAssignVariable,
	typeIntegerAssignIndexed,
	typeIntegerAddVariable,
	typeIntegerAssignSensor,

#if defined(NXT) || defined(TETRIX)
	typeClearScreen,
	typeClearPixel,
	typeRectangleDraw,
	typeRectangleErase,
	typeRectangleFill,
	//typeIOMapRead,
#endif

	typeLongAssign,
	typeLongAssignIndexed,
	typeLongAdd,
	typeLongTimes,
	typeFloatAssign,
	typeFloatAdd,
	typeFloatTimes,
#if defined(hasTranscendentalSupport)
  typeSine,
	typeCosine,
#endif
  typeLogical,
	typeTrinaryAdd,
	typeTrinaryAddConstant1,
	typeTrinaryAddConstant2,

	typeLast,
} TInstructions;

#if defined(useLongs)
  long index;
#else
  int index;
#endif

TInstructions testType;
#if defined(useFloats)
float nElapsedTime[(TInstructions) typeLast];
#else
int nElapsedTime[(TInstructions) typeLast];
#endif

float fTemp;
short iArray[20];
long  lArray[20];
float fArray[20];

void measureTime(const TInstructions nInstructionType)
{
	int i;
	int j;
	int k;
#if defined(useLongs)
	long l1;
	long l2;
#endif

#if defined(useFloats)
	float idleLoopTime;
	float loopTime;
	float elapsed;
#else
	int idleLoopTime;
	int loopTime;
	int elapsed;
#endif

	const int kInitialValues = 511; // an arbitrary value

	testType = nInstructionType;
	//wait1Msec(200);

	// Some variable initialization.
	i  = random(10);
	j  = kInitialValues;
	k  = kInitialValues;
#if defined(useLongs)
	l1 = kInitialValues * 256;
	l2 = kInitialValues;
#endif
#if defined(useFloats)
	fTemp = 0.999999999;
#endif
	idleLoopTime = nElapsedTime[typeIdleLoop];

	time1[executionTimer] = 0;
	for (index = 1; index <= kNumberOfLoops; ++index)
	{
		//
		// to measure a different instruction type, simply change the
		// definition of the following constant.
		//
			//
			// Since 'nInstructionType' is a constant, code optimizer will eliminate
			// the 'switch' instruction and the 'dead code' for the unreachable
			// cases.
			//
		switch (nInstructionType)
		{
		case typeIdleLoop:
		{
		  break;
		}

		case typeAlive:
		{
			alive(); alive();	alive(); alive();	alive();
			alive(); alive(); alive(); alive(); alive();
			break;
		}

		case typeIntegerAssignConstant:
		{
			iArray[00] = 250; iArray[01] = 250; iArray[02] = 250; iArray[03] = 250; iArray[04] = 250;
			iArray[05] = 250; iArray[06] = 250; iArray[07] = 250; iArray[08] = 250; iArray[09] = 250;
			break;
		}

		case typeIntegerAssignVariable:
		{
			iArray[00] = i; iArray[01] = i; iArray[02] = i; iArray[03] = i; iArray[04] = i;
			iArray[05] = i; iArray[06] = i; iArray[07] = i; iArray[08] = i; iArray[09] = i;
			break;
		}

		case typeIntegerAssignSensor:
		{
			iArray[00] = SensorValue[in1]; iArray[01] = SensorValue[in1];
			iArray[02] = SensorValue[in1]; iArray[03] = SensorValue[in1];
			iArray[04] = SensorValue[in1]; iArray[05] = SensorValue[in1];
			iArray[06] = SensorValue[in1]; iArray[07] = SensorValue[in1];
			iArray[08] = SensorValue[in1]; iArray[09] = SensorValue[in1];
			break;
		}

		case typeIntegerAssignIndexed:
		{
			iArray[i + 00] = 50; iArray[i + 01] = 50; iArray[i + 02] = 50;
			iArray[i + 03] = 50; iArray[i + 04] = 50; iArray[i + 05] = 50;
			iArray[i + 06] = 50; iArray[i + 07] = 50; iArray[i + 08] = 50;
			iArray[i + 09] = 50;
			break;
		}
		case typeIntegerAddVariable:
		{
			// Have to use alternating assignments to 'i' and 'j'; otherwise
			// code optimizer will simplify into single 'i += 20*333'

			iArray[00] += i; iArray[01] += i; iArray[02] += i;
			iArray[03] += i; iArray[04] += i; iArray[05] += i;
			iArray[06] += i; iArray[07] += i; iArray[08] += i;
			iArray[09] += i;
			break;
		}

		case typeIntegerAddConstant:
		{
			// Have to use alternating assignments to 'i' and 'j'; otherwise
			// code optimizer will simplify into single 'i ++= 20*333'

			iArray[00] += 250; iArray[01] += 250; iArray[02] += 250;
			iArray[03] += 250; iArray[04] += 250; iArray[05] += 250;
			iArray[06] += 250; iArray[07] += 250; iArray[08] += 250;
			iArray[09] += 250;
			break;
		}

#if defined(useLongs)
		case typeLongAssign:
		{
			lArray[00] = 50; lArray[01] = 50; lArray[02] = 50;
			lArray[03] = 50; lArray[04] = 50; lArray[05] = 50;
			lArray[06] = 50; lArray[07] = 50; lArray[08] = 50;
			lArray[09] = 50;
			break;
		}

		case typeLongAssignIndexed:
		{
			lArray[i + 00] = 50; lArray[i + 01] = 50; lArray[i + 02] = 50;
			lArray[i + 03] = 50; lArray[i + 04] = 50; lArray[i + 05] = 50;
			lArray[i + 06] = 50; lArray[i + 07] = 50; lArray[i + 08] = 50;
			lArray[i + 09] = 50;
			break;
		}
#endif

#if defined(useLongs)
		case typeLongAdd:
		{
			lArray[00] += 120; lArray[01] += 120; lArray[02] += 120;
			lArray[03] += 120; lArray[04] += 120; lArray[05] += 120;
			lArray[06] += 120; lArray[07] += 120; lArray[08] += 120;
			lArray[09] += 120;
			break;
		}
#endif

#if defined(useLongs)
		case typeLongTimes:
		{
			lArray[00] *= 3; lArray[01] *= 3; lArray[02] *= 3;
			lArray[03] *= 3; lArray[04] *= 3; lArray[05] *= 3;
			lArray[06] *= 3; lArray[07] *= 3; lArray[08] *= 3;
			lArray[09] *= 3;
			break;
		}
#endif

#if defined(useFloats)
		case typeFloatAssign:
		{
			fArray[00] = 3.357; fArray[01] = 3.357; fArray[02] = 3.357;
			fArray[03] = 3.357; fArray[04] = 3.357; fArray[05] = 3.357;
			fArray[06] = 3.357; fArray[07] = 3.357; fArray[08] = 3.357;
			fArray[09] = 3.357;
			break;
		}

		case typeFloatAdd:
		{
			fArray[00] += fTemp; fArray[01] += fTemp; fArray[02] += fTemp;
			fArray[03] += fTemp; fArray[04] += fTemp; fArray[05] += fTemp;
			fArray[06] += fTemp; fArray[07] += fTemp; fArray[08] += fTemp;
			fArray[09] += fTemp;
			break;
		}

		case typeFloatTimes:
		{
			fArray[00] *= fTemp; fArray[01] *= fTemp; fArray[02] *= fTemp;
			fArray[03] *= fTemp; fArray[04] *= fTemp; fArray[05] *= fTemp;
			fArray[06] *= fTemp; fArray[07] *= fTemp; fArray[08] *= fTemp;
			fArray[09] *= fTemp;
			break;
		}
#endif

#if defined(NXT) || defined(TETRIX)
		case typeClearScreen:
		{
			eraseDisplay();
			eraseDisplay();
			eraseDisplay();
			eraseDisplay();
			eraseDisplay();

			eraseDisplay();
			eraseDisplay();
			eraseDisplay();
			eraseDisplay();
			eraseDisplay();
			break;
		}

		case typeClearPixel:
		{
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);

			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			nxtClearPixel(22, 22);
			break;
		}

		case typeRectangleErase:
		{
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);

			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			nxtEraseRect(22, 22, 52, 52);
			break;
		}

		case typeRectangleFill:
		{
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);

			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			nxtFillRect(22, 22, 52, 52);
			break;
		}

		case typeRectangleDraw:
		{
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);

			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			nxtDrawRect(22, 22, 52, 52);
			break;
		}

#if (0)
		case typeIOMapRead:
		{
			const int kOffset = 0;
			const int kNumberOfBytes = 1;
			byte nBuffer[10];
			const string pzModule1 = "UI.mod";
			const string pzModule2 = "Display.mod";
#if (0)

			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
			nxtReadIOMap(pzModule1, ioResult, nBuffer[0], kOffset, kNumberOfBytes);
#else
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 1;
			nUiOMap.OBPPointer += 20;
#endif
			break;
		}
#endif
#endif

#if defined(hasTranscendentalSupport)
		case typeSine:
		{
			fTemp *= 1.5;
			fArray[00] = sin(fTemp); fArray[01] = sin(fTemp); fArray[02] = sin(fTemp);
			fArray[03] = sin(fTemp); fArray[04] = sin(fTemp); fArray[05] = sin(fTemp);
			fArray[06] = sin(fTemp); fArray[07] = sin(fTemp); fArray[08] = sin(fTemp);
			fArray[09] = sin(fTemp);
			break;
		}

		case typeCosine:
		{
			fTemp *= 1.5;
			fArray[00] = cos(fTemp); fArray[01] = cos(fTemp); fArray[02] = cos(fTemp);
			fArray[03] = cos(fTemp); fArray[04] = cos(fTemp); fArray[05] = cos(fTemp);
			fArray[06] = cos(fTemp); fArray[07] = cos(fTemp); fArray[08] = cos(fTemp);
			fArray[09] = cos(fTemp);
			break;
		}
#endif

		case typeLogical:
		{
#if defined(useLongs)
			i = (l1 < l2); i = (l1 < l2); i = (l1 < l2); i = (l1 < l2); i = (l1 < l2);
			i = (l1 < l2); i = (l1 < l2); i = (l1 < l2); i = (l1 < l2); i = (l1 < l2);
#endif
			break;
		}

		case typeTrinaryAdd:
		{
			iArray[00] = i + k; iArray[01] = i + k; iArray[02] = k + i;
			iArray[03] = i + k; iArray[04] = i + k; iArray[05] = k + i;
			iArray[06] = i + k; iArray[07] = i + k; iArray[08] = k + i;
			iArray[09] = i + k;
			break;
		}

		case typeTrinaryAddConstant1:
		{
			iArray[00] = i + 333; iArray[01] = i + 333; iArray[02] = 333 + i;
			iArray[03] = i + 333; iArray[04] = i + 333; iArray[05] = 333 + i;
			iArray[06] = i + 333; iArray[07] = i + 333; iArray[08] = 333 + i;
			iArray[09] = i + 333;
			break;
		}

		case typeTrinaryAddConstant2:
		{
			iArray[00] = i + 127; iArray[01] = i + 127; iArray[02] = 127 + i;
			iArray[03] = i + 127; iArray[04] = i + 127; iArray[05] = 127 + i;
			iArray[06] = i + 127; iArray[07] = i + 127; iArray[08] = 127 + i;
			iArray[09] = i + 127;
			break;
		}
	}
	}
	loopTime = time1[executionTimer];
#if defined(useFloats)
	loopTime /= 100.0;
#endif
	if (nInstructionType == typeIdleLoop)
	  elapsed = loopTime;
	else
	  elapsed = loopTime - idleLoopTime;
	nElapsedTime[nInstructionType] = elapsed;


	// 'elapsed' contains the number of 10 msec 'ticks' to execute 100,000 (5,000 loops
	// each with 20) statements. Thus if 'elapsed' is 146, a single statement took
	// 14.6 microseconds:
	//   - 1,460 millisecons total 'adjusted' time in loop (146 ticks x 10 milliseconds)
	//   - 1,460 milliseconds is same as 1,460,000 microseconds
	//   - divide by 100,000 to get 14.6 microseconds

	PlaySound(soundBlip);
	return;
}



task main()
{
	wait1Msec(200);
	SensorType[left] 		= testSensorType;
	SensorType[middle] 	= testSensorType;
	SensorType[right] 	= testSensorType;
	bFloatConversionErrors = false;

  for (TInstructions index = typeIdleLoop; index < typeLast; ++index)
		nElapsedTime[index] = 0;


	//memset(nElapsedTime, 0, sizeof(nElapsedTime));

	while (true)
	{
	  measureTime(typeIdleLoop);
		measureTime(typeAlive);

		measureTime(typeIntegerAssignConstant);
		measureTime(typeIntegerAddConstant);
		measureTime(typeIntegerAssignVariable);
		measureTime(typeIntegerAssignIndexed);
		measureTime(typeIntegerAddVariable);
		measureTime(typeIntegerAssignSensor);

		measureTime(typeLongAssign);
		measureTime(typeLongAssignIndexed);
		measureTime(typeLongAdd);
		measureTime(typeLongTimes);

		measureTime(typeFloatAssign);
		measureTime(typeFloatAdd);
		measureTime(typeFloatTimes);
	#if defined(hasTranscendentalSupport)
		measureTime(typeSine);
		measureTime(typeCosine);
	#endif

		measureTime(typeLogical);

		measureTime(typeTrinaryAdd);
		measureTime(typeTrinaryAddConstant1);
		measureTime(typeTrinaryAddConstant2);

	#if defined(NXT) || defined(TETRIX)
		measureTime(typeClearScreen);
		measureTime(typeClearPixel);
		measureTime(typeRectangleDraw);
		measureTime(typeRectangleErase);
		measureTime(typeRectangleFill);
		//measureTime(typeIOMapRead);
	#endif


		PlaySound(soundBeepBeep);
	}
	return;
}
