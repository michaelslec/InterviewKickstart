#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct AlgorithmTest {
  int array_size;
  int array_item_max;
  int rounds;
  void (*algorithm)(int *, int);
} AlgorithmTest;

void swap(int *, int *);
void bubbleSort(int *, int);
void printIntArray(int *, int);
void insertionSort(int *, int);
void selectionSort(int *, int);
void randomizeArray(int *, int, int);
double timeSortAlgorithm(AlgorithmTest, int);
AlgorithmTest createTest(int, int, int, void (*algorithm)(int *, int));

double rampingNSortTest(AlgorithmTest, int);

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

double rampingNSortTest(AlgorithmTest params, int percentage_increase) {
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
                         void (*algorithm)(int *, int)) {
  AlgorithmTest test;
  test.array_size = size;
  test.array_item_max = max;
  test.rounds = rounds;
  test.algorithm = algorithm;

  return test;
}

double timeSortAlgorithm(AlgorithmTest params, int print) {
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

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - i - 1; ++j)
      if (array[j] > array[j + 1])
        swap(&array[j], &array[j + 1]);
}

void printIntArray(int *array, int size) {
  printf("Array: ");
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

void insertionSort(int *array, int size) {
  for (int i = 1; i < size; ++i) {
    int j = i - 1;
    int tmp = array[i];

    while (j >= 0 && tmp < array[j]) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = tmp;
  }
}

void selectionSort(int *array, int size) {
  for (int i = 0; i < size - 1; ++i) {
    int min_idx = i;
    for (int j = i + 1; j < size; ++j)
      if (array[j] < array[min_idx])
        min_idx = j;
    swap(&array[i], &array[min_idx]);
  }
}

void randomizeArray(int *array, int size, int max) {
  for (int i = 0; i < size; ++i)
    array[i] = rand() % max;
}
