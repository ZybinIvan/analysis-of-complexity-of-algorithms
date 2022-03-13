#ifndef INC_5C_TESTINGFUCTIONS_H
#define INC_5C_TESTINGFUCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE (a) sizeof (a) / sizeof (a [0])

#define TIME_TEST ( testCode , time ) { \
    clock_t start_time = clock (); \
    testCode \
        clock_t end_time = clock () ;\
    clock_t sort_time = end_time - start_time ; \
    time = ( double ) sort_time / CLOCKS_PER_SEC ; \
}

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                   // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64];                       // имя генератора,
    // используемое при выводе
} GeneratingFunc;

double getTime() {
    clock_t start_time = clock();
    // фрагмент кода
    // время которого измеряется
    clock_t end_time = clock();\
    clock_t sort_time = end_time - start_time;
    return (double) sort_time / CLOCKS_PER_SEC;
}

void timeExperiment();

#endif
