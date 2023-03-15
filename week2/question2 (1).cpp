//Write a OpenMP program to calculate pow(i,x) for all the threads where i is an integer value and x is the thread_Id.
#include<stdio.h>
#include <math.h> 
#include<omp.h>
int main(){
	int i;
	printf("Enter the power: ");
	scanf("%d",&i);
	#pragma omp parallel
	{
		printf("multiplied power for %d thread: %f \n",omp_get_thread_num(),pow(omp_get_thread_num(),i));
	}
}
