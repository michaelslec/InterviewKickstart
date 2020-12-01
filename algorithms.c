#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "testing.h"

int *rightSplit(int *array, int size) {
  int offset = size / 2;
  int *new = malloc(sizeof(int) * (size + 1 / 2));
  for (int i = 0; i < size + 1 / 2; ++i)
    new[i] = array[i + offset];

  return new;
}

int *leftSplit(int *array, int size) {
  int *new = malloc(sizeof(int) * (size / 2));
  for (int i = 0; i < size / 2; ++i)
    new[i] = array[i];

  return new;
}

int *merge(int *left, int *right, int left_size, int right_size) {
  int *merged_arr = malloc(sizeof(int) * (left_size + right_size));
  int l_idx = 0, r_idx = 0;

  for (int i = 0; i < left_size + right_size; ++i) {
    if ((r_idx >= right_size || left[l_idx] < right[r_idx]) &&
        l_idx < left_size) {
      merged_arr[i] = left[l_idx];
      l_idx++;
    } else {
      merged_arr[i] = right[r_idx];
      r_idx++;
    }
  }

  free(left);
  free(right);
  return merged_arr;
}

int *mergeSort(int *array, int size) {
  if (size <= 1)
    return array;

  int left_size = size / 2, right_size = (size + 1) / 2;

  int *left_ptr = leftSplit(array, size);
  int *right_ptr = rightSplit(array, size);

  int *left = mergeSort(left_ptr, left_size);
  if (left_ptr != left)
    free(left_ptr);

  int *right = mergeSort(right_ptr, right_size);
  if (right_ptr != right)
    free(right_ptr);

  return merge(left, right, left_size, right_size);
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
