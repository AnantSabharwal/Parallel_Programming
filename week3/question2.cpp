#include <stdio.h>
#include <omp.h>
#include<time.h>

#define N 10

int main() {
	clock_t start,end;
    int i, j;
    double A[N][N], x[N], y[N];

    // Initialize A and x
    for (i = 0; i < N; i++) {
        x[i] = i;
        for (j = 0; j < N; j++) {
            A[i][j] = i + j;
        }
    }
	start = clock();
    // Perform matrix-vector multiplication
    #pragma omp parallel for private(j)
    for (i = 0; i < N; i++) {
        y[i] = 0;
        for (j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
	end = clock();
    // Print result
    for (i = 0; i < N; i++) {
        //printf("y[%d] = %f \n", i, y[i]);
        printf("%f ", y[i]);
    }
    printf("\n time taken %f ",end-start);

    return 0;
}

