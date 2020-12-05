#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithms.h"
#include "testing.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));

    const int rounds = argc >= 2 ? atoi(argv[1]) : 10;
    const int size = argc == 3 ? atoi(argv[2]) : 100000;

    /* double quick_sort_avg = timeSortAlgorithm(createTest(size, INT_MAX, rounds, quickSort), 1); */
    /* printf("Quick sort test: %.3fμs(%.3fs)\n", quick_sort_avg, quick_sort_avg / 1000000.0); */
    rampingNSortTest(createTest(size, INT_MAX, rounds, quickSort), 50);
    rampingNSortTest(createTest(size, INT_MAX, rounds, mergeSort), 50);

    return 0;
}
