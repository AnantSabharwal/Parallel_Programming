#include<stdio.h>
#include<mpi.h>
#include<math.h>

int main(int argc, char* argv[]) {
	int num = 5, rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	printf("Process %d: %d power %d = %lf \n", rank, num, rank, pow(num, rank));

	MPI_Finalize();

	return 0;
}
