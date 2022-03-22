#ifndef INC_5C_SORTS_H
#define INC_5C_SORTS_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <memory.h>

#include "../algorithms/algorithms.h"

void bubbleSort(int *a, size_t size);

long long getBubbleSortNComp(int *a, size_t size);

void selectionSort(int *a, size_t size);

long long getSelectionSortNComp(int *a, size_t size);

void insertionSort(int *a, size_t size);

long long getInsertionSortNComp(int *a, size_t size);

void combSort(int *a, size_t size);

long long getCombSortNComp(int *a, size_t size);

void shellSort(int *a, size_t size);

long long getShellSortNComp(int *a, size_t size);

void radixSort(int *a, size_t size);

long long getRadixSortNComp(int *a, size_t size);

#endif