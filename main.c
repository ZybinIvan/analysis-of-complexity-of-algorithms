#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "libs/sorts/sorts.h"
#include "libs/algorithms/algorithms.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
    clock_t end_time = clock();\
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n);    // указатель на функцию сортировки
    char name[64];                      // имя сортировки, используемое при выводе
} SortFunc;

typedef struct SortFuncNComps {
    long long (*sort)(int *a, size_t n);

    char name[64];
} SortFuncNComps;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n);    // указатель на функцию генерации последовательности
    char name[64];                          // имя генератора, используемое при выводе
} GeneratingFunc;

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;
    // генерация последовательности
    static int innerBuffer[10000000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name : %s\n", experimentName);
    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time);

    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3f s.\n", time);
        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv ", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong !\n");
        outputArray(innerBuffer, size);
        exit(1);
    }
}

void timeExperiment() {
    // описание функций сортировки
    SortFunc sorts[] = {
//            {bubbleSort, "bubble sort"},
//            {selectionSort, "selection sort"},
//            {insertionSort, "insertion sort"},
//            {combSort, "comb sort"},
//            {shellSort, "shell sort"},
            {radixSort, "digit sort"},

    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);
    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      "random"},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     "ordered"},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);
    // запись статистики в файл
    for (size_t size = 1000000; size <= 10000000; size += 1000000) {
        printf("------------------------------\n");
        printf(" Size : %lld\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                char filename[128];
                sprintf(filename, "%s_%s_time", sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort, generatingFuncs[j].generate, size, filename);
            }
        }
        printf("\n");
    }
}

void checkNComps(long long (*sortFunc)(int *, size_t), void (*generateFunc)(int *, size_t), size_t size,
                 char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    long long nComps = sortFunc(innerBuffer, size);

    // результаты замера
    printf(" Status : ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Count of comparisons: %lld.\n", nComps);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf(" FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %lld\n", size, nComps);
        fclose(f);
    } else {
        printf(" Wrong !\n");
        outputArray(innerBuffer, size);
        exit(1);
    }
}

void comparisonsExperiment() {
    SortFuncNComps sorts[] = {
//            {getBubbleSortNComp,  "bubbleSort"},
//            {getSelectionSortNComp, "selectionSort"},
//            {getInsertionSortNComp, "insertionSort"},
//            {getCombSortNComp,      "combSort"},
//            {getShellSortNComp, "shellSort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            // генерируется случайный массив
            {generateRandomArray,      "random"},
            // генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray,     "ordered"},
            // генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf(" Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                char filename[128];
                sprintf(filename, "%s_%s_nComps", sorts[i].name, generatingFuncs[j].name);
                checkNComps(sorts[i].sort, generatingFuncs[j].generate, size, filename);
            }
        }
        printf("\n");
    }
}

int main() {
    timeExperiment();

    return 0;
}