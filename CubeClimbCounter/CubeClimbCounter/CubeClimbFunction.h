#pragma once

int cubeStepsCounter(int N, int pastStep)
{
    if (N == 0)
        return 1;

    int stepsResult = 0;

    for (int i = 1; i < pastStep; i++)
    {
        stepsResult += cubeStepsCounter(N - i, i);
    }

    return stepsResult;
}