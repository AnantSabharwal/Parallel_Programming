#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_BINS 6
#define BIN_WIDTH 1.5

int main()
{
    float A[1000];
    int histogram[NUM_BINS] = {0};
    int i;
	int bin;

    #pragma omp parallel for
    for (i = 0; i < 1000; i++) {
        A[i] = rand() % 100;
        A[i] = A[i]/10;
    }

    #pragma omp parallel for private(bin)
    for (i = 0; i < 1000; i++) {
        bin = A[i] / BIN_WIDTH; 
		#pragma omp atomic
        histogram[bin]++;
    }

    for (bin = 0; bin < NUM_BINS; bin++) {
        printf("[%2f-%2f]: %d\n", (float)bin*BIN_WIDTH, (float)(bin+1)*BIN_WIDTH-1, histogram[bin]);
    }

    return 0;
}

