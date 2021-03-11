#include <stdio.h>
#include <omp.h>

void t8_schedule() {
    const int size = 16000;
    int a[size];
    double b[size];

    for (int i = 0; i < size; i++)
        a[i] = i;

    double start = omp_get_wtime();
#pragma omp parallel for num_threads(8) schedule(static, 4)
    for (int i = 1; i < size - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    double end = omp_get_wtime();
    printf("static. time = %f\n", end - start);

    start = omp_get_wtime();
#pragma omp parallel for num_threads(8) schedule(dynamic, 8)
    for (int i = 1; i < size - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    end = omp_get_wtime();
    printf("dynamic. time = %f\n", end - start);

    start = omp_get_wtime();
#pragma omp parallel for num_threads(8) schedule(guided, 16)
    for (int i = 1; i < size - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    end = omp_get_wtime();
    printf("guided. time = %f\n", end - start);

    start = omp_get_wtime();
#pragma omp parallel for num_threads(8) schedule(runtime)
    for (int i = 1; i < size - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
    }
    end = omp_get_wtime();
    printf("runtime. time = %f\n", end - start);
}