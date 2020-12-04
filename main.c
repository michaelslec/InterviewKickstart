#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithms.h"
#include "testing.h"

int main()
{
  srand(time(NULL));

  const int size = 1000000;
  int array[size];

  clock_t exec_time;
  for (int i = 0; i < 20; ++i)
  {
    randomizeArray(array, size, INT_MAX);

    exec_time = clock();
    insertionSort(array, size);
    exec_time = clock() - exec_time;

    printf("That took %ldμs(%.3fs)\n", exec_time,
           (double)exec_time / 1000000.0);
  }

  double merge_sort_average =
      timeSortAlgorithm(createTest(1000000, 20000, 10, mergeSort), 1);
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
