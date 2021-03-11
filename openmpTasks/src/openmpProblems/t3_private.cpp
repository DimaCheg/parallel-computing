#include <stdio.h>
#include <omp.h>

void t3_private() {
    int a = 4, b = 7;

    printf("before 1st. a = %d. b = %d \n", a, b);
#pragma omp parallel private(a) firstprivate(b) num_threads(2)
    {
        int thread_num = omp_get_thread_num();
        a += thread_num;
        b += thread_num;
        printf("area 1. a = %d. b = %d \n", a, b);
    }
    printf("after 1st. a = %d. b = %d \n\n", a, b);

    printf("before 2nd. a = %d. b = %d \n", a, b);
#pragma omp parallel shared(a) private(b) num_threads(4)
    {
        int thread_num = omp_get_thread_num();
        a -= thread_num;
        b -= thread_num;
        printf("area 2. a = %d. b = %d \n", a, b);
    }
    printf("after 2nd. a = %d. b = %d \n", a, b);
}