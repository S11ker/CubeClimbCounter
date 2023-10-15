#include "pch.h"
#include "CppUnitTest.h"
#include "../CubeClimbCounter/CubeClimbFunction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cubeStepsCounterTests
{
	TEST_CLASS(cubeStepsCounterTests)
	{
	public:
		
		TEST_METHOD(creatingStepsWitnMinNumberOfCubes)
		{
			int stepsResult = cubeStepsCounter(1, 2);
			int expStepsResult = 1;
			Assert::AreEqual(expStepsResult, stepsResult);
		}

		TEST_METHOD(creatingStepsWitnMeanNumberOfCubes)
		{
			int stepsResult = cubeStepsCounter(50, 51);
			int expStepsResult = 3658;
			Assert::AreEqual(expStepsResult, stepsResult);
		}

		TEST_METHOD(creatingStepsWitnMaxNumberOfCubes)
		{
			int stepsResult = cubeStepsCounter(100, 101);
			int expStepsResult = 444793;
			Assert::AreEqual(expStepsResult, stepsResult);
		}

		TEST_METHOD(creatingStepsWitnNoNumberOfCubes)
		{
			int stepsResult = cubeStepsCounter(0, 1);
			int expStepsResult = 1;
			Assert::AreEqual(expStepsResult, stepsResult);
		}
	};
}
