#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[]) {
	int a = 5, b = 2, rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0)
		printf("%d + %d = %d \n", a, b, a + b);
	else if (rank == 1)
		printf("%d - %d = %d \n", a, b, a - b);
	else if (rank == 2)
		printf("%d * %d = %d \n", a, b, a * b);
	else
		printf("%d / %d = %f \n", a, b, (float)a / b);

	MPI_Finalize();

	return 0;
} 
