#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "testing.h"

double rampingNSortTest(AlgorithmTest params, int percentage_increase)
{
    printf("RAMPING N TEST:\n");

    int rounds = params.rounds;
    double prev = 0, curr = 0, sum = 0,
           increase = 1 + (double)percentage_increase / 100.0;
    params.rounds = 1;

    for (int i = 0; i < rounds; ++i) {
        printf("Round %d: Sorting %d items... ", i + 1, params.array_size);

        curr = timeSortAlgorithm(params, 0);
        sum += curr;
        params.array_size *= increase;

        if (i != 0)
            printf("%.3fs. Delta %.3fs (%%%.2f)\n", curr / 1000000.0,
                (curr - prev) / 1000000.0, (curr / prev) * 100.0);
        else
            printf("%.3fs\n", curr / 1000000.0);

        prev = curr;
    }

    return sum / (double)rounds;
}

AlgorithmTest createTest(int size, int max, int rounds,
    void (*algorithm)(int*, int))
{
    AlgorithmTest test;
    test.array_size = size;
    test.array_item_max = max;
    test.rounds = rounds;
    test.algorithm = algorithm;

    return test;
}

double timeSortAlgorithm(AlgorithmTest params, int print)
{
    int array[params.array_size];

    if (print)
        printf("NEW SORTING TEST:\n");

    clock_t exec_time;
    int sum = 0;
    for (int i = 0; i < params.rounds; ++i) {
        randomizeArray(array, params.array_size, params.array_item_max);
        /* printIntArray(array, params.array_size); */

        exec_time = clock();
        params.algorithm(array, params.array_size);
        exec_time = clock() - exec_time;
        /* printIntArray(array, params.array_size); */

        sum += exec_time;
        if (print)
            printf("Round %2d: Algorithm took %ld microseconds (%.2f seconds)\n",
                i + 1, exec_time, (double)exec_time / 1000000.0);
    }
    if (print)
        printf("\n");

    return (double)sum / (double)params.rounds;
}

void printIntArray(int* array, int size)
{
    printf("Array: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

void randomizeArray(int* array, int size, int max)
{
    for (int i = 0; i < size; ++i)
        array[i] = rand() % max;
}
