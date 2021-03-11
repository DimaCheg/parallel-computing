#include <omp.h>
#include <stdio.h>

void t7_schedule() {
    const int size = 12;
    int a[size], b[size], c[size];

#pragma omp parallel for schedule(static, 2) num_threads(3)
    for (int i = 0; i < size; i++) {
        a[i] = i;
        b[i] = 2 * i;
        int thread_num = omp_get_thread_num();
        printf("thread number %d. a = %d. b = %d\n", thread_num, a[i], b[i]);
    }

#pragma omp parallel for schedule(dynamic, 3) num_threads(4)
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
        int thread_num = omp_get_thread_num();
        printf("thread number %d. c = %d\n", thread_num, c[i]);
    }
}