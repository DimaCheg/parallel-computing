#include <stdio.h>
#include <omp.h>
#include <iostream>

void t12_div() {
    const int size = 64;
    int a[size];
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
        a[i] = rand();

#pragma omp parallel for firstprivate(a) shared(max) num_threads(4)
    for (int i = 0; i < size; i++) {
        if (a[i] % 7 == 0 && a[i] > max)
#pragma omp critical
            max = a[i];
    }

    printf("max = %d\n", max);
}