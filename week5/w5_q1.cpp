#include <stdio.h>
#include <omp.h>
#include<time.h>
#define N 100
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int i, a[N], b[N], c[N], d[N], e[N],f[N],g[N],h[N];
    clock_t start,end;
    // Initialize arrays
    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = N - i;
        //c[i] = 0;
        //d[i] = i % 10;
        //e[i] = 1;
    }
    printf("A \n");
    printArray(a,N);
    printf("B \n");
    printArray(b,N);
    
    //sequential
    printf("Sequential Execution");
    start = clock();
    for(i=0;i<N;i++){
    	c[i] = a[i]+b[i];
    	d[i] = a[i]-b[i];
    	e[i] = a[i]*b[i];
	}
	end = clock();
	float t_seq,t_par;
	t_seq = float(end-start);
	printf("Sequential Time %f\n",t_seq);
    
    printf("Parallel Execution");
    start = clock();
    #pragma omp parallel sections shared(a, b, f, g, h)
    {
        #pragma omp section
        {
        	#pragma omp parallel for
            for (i = 0; i < N; i++) {
                f[i] = a[i] + b[i];
            }
        }
        
        #pragma omp section
        {
        	#pragma omp parallel for
            for (i = 0; i < N; i++) {
                g[i] = (a[i] - b[i]);// * e[i];
            }
        }
        
        #pragma omp section
        {
        	#pragma omp parallel for
            for (i = 0; i < N; i++) {
                h[i] = a[i] * b[i];
            }
        }
    }
    end = clock();
    t_par = (float)(end-start);
	printf("Parallel Time %f\n",t_par);
	
    printf("C \n");
    printArray(c,N);
    printf("D \n");
    printArray(d,N);
    printf("E \n");
    printArray(e,N);
    printf("F \n");
    printArray(f,N);
    printf("G \n");
    printArray(g,N);
    printf("H \n");
    printArray(h,N);
    // Print results
    //printf("Vector addition: %d\n", c[0]);
    //printf("Vector subtraction: %d\n", d[0]);
    //printf("Vector multiplication: %d\n", e[0]);
    
    return 0;
}


