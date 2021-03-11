#include <iostream>
#include <mpi.h>

void t1_hw() {
    MPI_Init(NULL, NULL);
    printf("Hello world!\n");
    MPI_Finalize();
}
