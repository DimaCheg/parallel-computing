#include <stdio.h>
#include <omp.h>
#include <cstdlib>

void t11_atomic() {
    const int size = 30;// columns
    int a[size];
    int k = 0;

    for (int i = 0; i < size; i++)
        a[i] = rand();

#pragma omp parallel for shared(a, k) num_threads(4)
    for (int i = 0; i < size; i++) {
        if (a[i] % 9 == 0) {
#pragma omp atomic
            k++;
        }
    }
    printf("%d", k);
}