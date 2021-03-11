#include <omp.h>
#include <stdio.h>

void print_thread_number() {
    int id = omp_get_thread_num();
    int num = omp_get_num_threads();
    printf("thread id: %d. number of threads: %d \n", id, num);
}

void t2_if() {
    int count = 3;
#pragma omp parallel if(count > 2) num_threads(count)
    {
        print_thread_number();
    }

    count = 2;
#pragma omp parallel if(count > 2) num_threads(count)
    {
        print_thread_number();
    }
}