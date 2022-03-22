#include "algorithms.h"

bool isOrdered(const int *a, size_t n) {
    for (size_t i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;

    return true;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void inputArray(int *a, size_t size) {
    for (size_t i = 0; i < size; ++i)
        scanf("%d", &a[i]);
}

void outputArray(const int *a, size_t size) {
    for (size_t i = 0; i < size; ++i)
        printf("%d ", a[i]);
}

void generateRandomArray(int *a, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++)
        a[i] = rand();
}

void generateRandomArrayWithNegative(int *a, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        if (i % 2)
            a[i] = rand();
        else
            a[i] = rand() % 100 - rand();
    }
}

void generateOrderedArray(int *a, size_t size) {
    for (int i = 0; i < size; ++i)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t size) {
    int j = 0;
    for (int i = size - 1; i >= 0; --i)
        a[j++] = i;
}


