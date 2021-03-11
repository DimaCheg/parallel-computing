#include <stdio.h>
#include <omp.h>
#include <iostream>

void t4_minmax() {
    const int size = 10;
    int min = abs(size * 1000), max = -abs(size * 1000);
    int a[size], b[size];

    for (int i = 0; i < size; i++) {
        a[i] = i, b[i] = 2 * i;
    }

#pragma omp parallel num_threads(2)
    {
        if (omp_get_thread_num() == 0) {
            for (int i = 0; i < size; i++) {
                if (a[i] < min)
                    min = a[i];
            }
            printf("min value of a[] = %d\n", min);
        } else {
            for (int j = 0; j < size; j++) {
                if (b[j] > max)
                    max = b[j];
            }
            printf("max value of b[] = %d\n", max);
        }
    }
}