#include <iostream>
#include "CubeClimbFunction.h"
#include "WorkWithIFDInTxtFile.h"

int main()
{
    int stepsResult = cubeStepsCounter(100, 101);
    cout << stepsResult << endl;
}

