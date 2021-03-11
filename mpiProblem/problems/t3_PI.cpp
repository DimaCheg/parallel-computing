#include <iostream>
#include <mpi.h>
#include <cmath>

void t3_pi() {
    MPI_Init(NULL, NULL);
    int n = 10000, k = 0, rank, size;
    double a, b;// = sqrt(2.), b=sqrt(3.);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int p = n / size;
    int local = 0;
    for (int i = rank * p; i < p * (rank + 1); i++) {
        double ipart;
        a = modf(sqrt(2) * i, &ipart);
        b = modf(sqrt(3) * i, &ipart);
        if (a * a + b * b <= 1)
            local++;
    }

    MPI_Reduce(&local, &k, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double res = k / (double) n;
        printf("%f", res);
    }
}