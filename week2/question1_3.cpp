#include<bits/stdc++.h>
#include<stdio.h>
#include<omp.h>
int main(){
	#pragma omp parallel 
    {
        int id = omp_get_thread_num();
        int numThreads = omp_get_num_threads();
        printf("Hello from thread %d of %d\n", id, numThreads);
    }

    printf("\n");
    return 0;
}

