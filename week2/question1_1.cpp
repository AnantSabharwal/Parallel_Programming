#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
int main(void){
	printf("Before: %d \n",omp_get_num_threads());
	#pragma omp parallel
	{
		printf("Thread ID: %d \n",omp_get_thread_num());
	}
	printf("After: %d \n",omp_get_num_threads());
	return 0;
}
