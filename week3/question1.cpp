#include <stdio.h>
#include <omp.h>
#include <time.h>

const int N = 400;

int matrix_multiply(int A[][N], int B[][N], int C[][N], int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
	clock_t start_time,end_time;
	int size[] = {200,400,600,800,1000};
	
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    start_time = clock();

    matrix_multiply(A, B, C, N);

    end_time = clock();

    for (int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		printf("%d ",C[i][j]);
		}
		printf("\n");
	}

    printf("Time taken: %f seconds\n", end_time - start_time);

    return 0;
}

