#include <omp.h>
#include <stdio.h>

void t1_hello_world() {
#pragma omp parallel num_threads(8)
    {
        int id = omp_get_thread_num();
        int num = omp_get_num_threads();
        printf("Hello World. thread id: %d. number of threads: %d \n", id, num);
    }
}