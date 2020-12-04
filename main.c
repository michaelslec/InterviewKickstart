#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithms.h"
#include "testing.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));

    const int size = argc == 2 ? atoi(argv[1]) : 100000;
    int array[size];
    randomizeArray(array, size, 2 * size);
    printIntArray(array, size);
    quickSort(array, size);
    printIntArray(array, size);

    /* printf("Average: %.3f seconds\n", timeSortAlgorithm(createTest(size, 20000,
   * 20, mergeSort), 1) / 1000000.0); */
    /* double insertion_sort_average = */
    /*     timeSortAlgorithm(createTest(1100000, 20000, 10, insertionSort), 1); */
    /* double selection_sort_average = */
    /*     timeSortAlgorithm(createTest(1100000, 20000, 10, selectionSort), 1); */

    /* printf("      merge      insertion      selection\n"); */
    /* printf("%11.2f %14.2f %14.2f\n", merge_sort_average / 1000000.0, */
    /*        insertion_sort_average / 1000000.0, */
    /*        selection_sort_average / 1000000.0); */

    return 0;
}
