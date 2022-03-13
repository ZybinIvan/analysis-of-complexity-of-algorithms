#ifndef INC_5C_ALGORITHMS_H
#define INC_5C_ALGORITHMS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool isOrdered(const int *a, size_t n);

void swap(int *a, int *b);

void inputArray(int *a, size_t size);

void outputArray(const int *a, size_t size);

void generateRandomArray(int *a, size_t size);

void generateOrderedArray(int *a, size_t size);

void generateOrderedBackwards(int *a, size_t size);

#endif //INC_5C_ALGORITHMS_H
