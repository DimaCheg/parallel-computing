#include <stdio.h>
#include <omp.h>

void t9_scm() {
    const int size = 64;
    int matrix[size][size], vec[size], result[size];
    double start, end;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            matrix[i][j] = i;
        vec[i] = i;
    }

    start = omp_get_wtime();
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++)
            result[i] += matrix[i][j] * vec[j];
    }
    end = omp_get_wtime();
    printf("not parallel. time = %f\n", end - start);

    start = omp_get_wtime();
#pragma omp parallel for num_threads(4) schedule(runtime)
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++)
            result[i] += matrix[i][j] * vec[j];
    }
    end = omp_get_wtime();
    printf("schedule runtime. time = %f\n", end - start);
}