#include <stdio.h>
#include <omp.h>
#include <iostream>

using namespace std;

void t5_section() {
    const int size1 = 6, // rows
    size2 = 8; // columns
    int d[size1][size2];

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            d[i][j] = rand();
        }
    }

#pragma omp parallel sections shared(d)
    {
        // среднее арифметическое массива
#pragma omp section
        {
            double sum = 0;
            for (auto &subnumbers : d) {
                for (int num : subnumbers) {
                    sum += num;
                }
            }
            double average = sum / (double) (size1 * size2);
            printf("Arithmetic mean = %f. from thread %d \n", average, omp_get_thread_num());
        }

        // минимальное и максимальное значения массива
#pragma omp section
        {
            int min = INT_MAX;
            int max = INT_MIN;
            for (auto &subnumbers : d) {
                for (int num : subnumbers) {
                    if (num < min)
                        min = num;

                    if (num > max)
                        max = num;
                }
            }
            printf("max value = %d. min value = %d. from thread %d \n", max, min, omp_get_thread_num());
        }

        // количество элементов массива, кратных 3
#pragma omp section
        {
            int count = 0;
            for (auto &subnumbers : d) {
                for (int num : subnumbers) {
                    if (num % 3 == 0)
                        count++;
                }
            }
            printf("count = %d. from thread %d \n", count, omp_get_thread_num());
        }
    }
}