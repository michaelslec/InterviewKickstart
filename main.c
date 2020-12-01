#include <stdio.h>

#include "algorithms.h"
#include "testing.h"

int main() {
  srand(time(NULL));

  /* rampingNSortTest(createTest(1000, 10000, 10, bubbleSort), 50); */
  rampingNSortTest(createTest(1000, 10000, 13, insertionSort), 50);

  double bubble_sort_average =
      timeSortAlgorithm(createTest(10000, 20000, 10, bubbleSort), 1);
  double insertion_sort_average =
      timeSortAlgorithm(createTest(10000, 20000, 10, insertionSort), 1);
  double selection_sort_average =
      timeSortAlgorithm(createTest(10000, 20000, 10, selectionSort), 1);

  printf("      bubble      insertion      selection\n");
  printf("%12.2f %14.2f %14.2f\n", bubble_sort_average / 1000000.0,
         insertion_sort_average / 1000000.0,
         selection_sort_average / 1000000.0);

  return 0;
}
