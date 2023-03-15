#include<stdio.h>
#include<omp.h>
int main(void){
	printf("Before1: %d \n");
	#pragma omp parallel
	{
		printf("Thread Number: %d \n",omp_get_thread_num());
	}
	printf("After1: %d \n");
	omp_set_num_threads(2);
	printf("Before2: %d \n");
	#pragma omp parallel
	{
		printf("Thread Number: %d \n",omp_get_thread_num());
	}
	printf("After2: %d \n");
	omp_set_num_threads(8);
	printf("Before3: %d \n");
	#pragma omp parallel
	{
		printf("Thread Number: %d \n",omp_get_thread_num());
	}
	printf("After3: %d \n");
	return 0;
}
