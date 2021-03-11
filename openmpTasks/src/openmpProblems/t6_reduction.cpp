#include <omp.h>
#include <stdio.h>

void t6_red(){
    const int size = 100;
    int a[size], sum=0;
    for (int i = 0; i < size; i++) {
        a[i]=i+i%3;
    }

#pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < size; i++)
    {
        sum+=a[i];
    }
    double mean = sum/double(size);
    printf("with reduction: %f\n", mean);

    sum=0;
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        sum+=a[i];
    }
    mean = sum/double(size);
    printf("without reduction: %f", mean);
}