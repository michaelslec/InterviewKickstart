#include "algorithms.h"

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
