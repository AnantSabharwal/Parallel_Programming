
#include <stdio.h>
#include<stdlib.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int num[5];
    int recv_num;
    int i, cube;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        printf("Enter 5 numbers:\n");
        for (i = 0; i < 5; i++) {
            scanf_s("%d", &num[i]);
        }
    }
    MPI_Bcast(num, 5, MPI_INT, 0, MPI_COMM_WORLD);
    recv_num = num[rank];
    cube = pow(recv_num, 3);
    int* cubes;
    cubes = (int*)malloc(size * sizeof(int));

    MPI_Gather(&cube, 1, MPI_INT, cubes, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Cubes of the given numbers:\n");
        for (i = 0; i < 5; i++) {
            printf("%d\n", cubes[i]);
        }
    }
    MPI_Finalize();
    return 0;
}
