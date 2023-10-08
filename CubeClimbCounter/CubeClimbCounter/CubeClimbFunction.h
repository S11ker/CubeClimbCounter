﻿#pragma once

/**
 * @brief Функция, которая решает главную задачу. 
 * 
 * Выполнена по принципу рекурсии и возвращает в 
 * конце своей работы количество лестниц, которое 
 * удалось построить из N кубиков.
 * 
 * @param [in] N - количество кубиков
 * @param [in] pastStep - количество кубиков на предыдущей ступени
 * @return stepsResult - количество лестниц, которые удалось построить из N кубиков
 */
int cubeStepsCounter(int N, int pastStep)
{
    //Проверка базового случая:
    if (N == 0) // если количество кубиков равно 0
        return 1; //считать, что лестницу удалось построить

    // Количество возможных лестниц
    int stepsResult = 0;

    for (int i = 1; i < pastStep; i++)
    {
        // Оставшееся количество кубиков после построения текущей ступеньки
        int leftCubesStep = N - i;
        
        // Если оставшееся количество кубиков после построения текущей ступеньки меньше нуля
        if (leftCubesStep < 0)
            break; // прервать выполнение цикла

        // Увеличить количество возможных лестниц на результат выполнения функции подсчета лестниц
        stepsResult += cubeStepsCounter(leftCubesStep, i);
    }

    // Вернуть общее количество лестниц, которые удалось построить
    return stepsResult;
}