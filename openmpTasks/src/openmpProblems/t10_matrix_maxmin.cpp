#include <stdio.h>
#include <omp.h>
#include <iostream>

void t10_maxtrix_maxmin() {
    const int size1 = 6, // rows
    size2 = 8; // columns
    int d[size1][size2];

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            d[i][j] = rand();

#pragma omp parallel for shared(d, min, max) num_threads(4)
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            {
                if (d[i][j] > max) {
#pragma omp critical
                    max = d[i][j];
                }
                if (d[i][j] < min) {
#pragma omp critical
                    min = d[i][j];
                }
            }
        }
    }

    printf("max value = %d. min value = %d\n", max, min);
}