#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "testing.h"

void merge(int* array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l_copy[n1], r_copy[n2];

    for (int i = 0; i < n1; ++i)
        l_copy[i] = array[left + i];

    for (int i = 0; i < n2; ++i)
        r_copy[i] = array[mid + 1 + i];

    int l_idx = 0, r_idx = 0;
    for (int k = left; k <= right; ++k) {
        // if the left array is the lower value OR
        // the right array has been exhausted AND
        // the left array has NOT been exhausted
        if ((r_idx >= n2 || l_copy[l_idx] < r_copy[r_idx]) && l_idx < n1) {
            array[k] = l_copy[l_idx];
            ++l_idx;
        } else { // otherwise
            array[k] = r_copy[r_idx];
            ++r_idx;
        }
    }
}

void _mergeSort(int* array, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right - 1) / 2;
    _mergeSort(array, left, mid);
    _mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

void mergeSort(int* array, int size)
{
    _mergeSort(array, 0, size - 1);
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}

void insertionSort(int* array, int size)
{
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

void selectionSort(int* array, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j)
            if (array[j] < array[min_idx])
                min_idx = j;
        swap(&array[i], &array[min_idx]);
    }
}
