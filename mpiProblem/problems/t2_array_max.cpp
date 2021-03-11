#include <iostream>
#include <mpi.h>

void t2_ar_max() {
    MPI_Init(NULL, NULL);

    int rank, size, n = 16, max = -1, localmax;
    int a[16];
    for (int i = 0; i < n; i++) {
        a[i] = i + i % 3;
    }

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int p = n / size;
    int *buffer = new int[p];

    MPI_Scatter(a, p, MPI_INT, buffer, p, MPI_INT, 0, MPI_COMM_WORLD);

    localmax = -1;
    for (int i = 0; i < p; i++) {
        if (buffer[i] > localmax) {
            localmax = buffer[i];
        }
    }

    MPI_Reduce(&localmax, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("max = %d", max);
    }
    MPI_Finalize();
}