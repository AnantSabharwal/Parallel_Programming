#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
	char str[10] = "Hello";
	int rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (str[rank] >= 97)
		str[rank] -= 32;
	else
		str[rank] += 32;
	printf("Process %d toggled character to %c \n", rank, str[rank]);

	MPI_Finalize();

	return 0;
}
