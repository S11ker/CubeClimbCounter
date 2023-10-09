#include <iostream>
#include "CubeClimbFunction.h"
#include "WorkWithIFDInTxtFile.h"

int main(const int argc, char** argv)
{
    int stepsResult = cubeStepsCounter(100, 101);
    cout << stepsResult << endl;
}

