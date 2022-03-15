#include "sorts.h"

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

long long getBubbleSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < size - 1; i++)
        for (size_t j = size - 1; ++nComps && j > i; j--)
            if (++nComps && a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);

    return nComps;
}

void selectionSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        size_t indexOfMin = i;
        for (size_t j = i; j < size; ++j)
            if (a[j] < a[indexOfMin])
                indexOfMin = j;
        if (i != indexOfMin)
            swap(&a[i], &a[indexOfMin]);
    }
}

long long getSelectionSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < size - 1; ++i) {
        size_t indexOfMin = i;
        for (size_t j = i; ++nComps && j < size; ++j)
            if (++nComps && a[j] < a[indexOfMin])
                indexOfMin = j;
        if (++nComps && i != indexOfMin)
            swap(&a[i], &a[indexOfMin]);
    }

    return nComps;
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

long long getInsertionSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 1; ++nComps && i < size; ++i) {
        int t = a[i];
        int j = i;
        while (++nComps && j > 0 && ++nComps && ++nComps && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }

    return nComps;
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

long long getCombSortNComp(int *a, size_t size) {
    long long nComps = 0;
    size_t step = size;
    bool swapped = true;
    while (++nComps && step > 1 || swapped) {
        if (++nComps && step > 1)
            step /= 1.24733;

        swapped = false;
        for (size_t i = 0, j = i + step; ++nComps && j < size; i++, j++)
            if (++nComps && a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = true;
            }
    }

    return nComps;
}

void shellSort(int *a, size_t size) {
    for (int s = size / 2; s > 0; s /= 2)
        for (int i = s; i < size; i++)
            for (int j = i - s; j >= 0 && a[j] > a[j + s]; j -= s)
                swap(&a[j], &a[j + s]);
}

long long getShellSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int s = size / 2; ++nComps && s > 0; s /= 2)
        for (int i = s; ++nComps && i < size; i++)
            for (int j = i - s; ++nComps && j >= 0 && ++nComps && ++nComps && a[j] > a[j + s]; j -= s)
                swap(&a[j], &a[j + s]);

    return nComps;
}


void radixSort(int *a, size_t size) {

}
