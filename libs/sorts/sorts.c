#include "sorts.h"

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        size_t indexOfMin = i;
        for (size_t j = i; j < size; ++j)
            if (a[j] < a[indexOfMin])
                indexOfMin = j;
        swap(&a[i], &a[indexOfMin]);
    }
}

void insertionSort(int *a, size_t size) {
    for (int i = 1; i < size; ++i) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combSort(int *a, size_t size) {
    size_t step = size;
    bool swapped = true;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;

        swapped = false;
        for (size_t i = 0, j = i + step; j < size; i++, j++)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = true;
            }
    }
}

void shellSort(int *a, size_t size) {
    for (int s = size / 2; s > 0; s /= 2)
        for (int i = s; i < size; i++)
            for (int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s)
                swap(&a[j], &a[j + s]);
}
