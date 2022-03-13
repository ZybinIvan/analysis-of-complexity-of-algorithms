#ifndef INC_5C_SORTS_H
#define INC_5C_SORTS_H

#include <stdio.h>
#include <stdbool.h>

#include "../algorithms/algorithms.h"

void bubbleSort(int *a, size_t size);

void selectionSort(int *a, size_t size);

void insertionSort(int *a, size_t size);

void combSort(int *a, size_t size);

void shellSort(int *a, size_t size);

#endif