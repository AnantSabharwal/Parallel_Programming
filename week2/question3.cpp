#include<stdio.h>
#include<omp.h>
#include<bits/stdc++.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int even_sum = 0 , odd_sum = 0;
	#pragma omp parallel for
	for(int i=0;i<10;i++){//sizeof(arr)
		if (arr[i]%2 == 0){
			even_sum += arr[i];
			printf("Thread Number: %d \n",omp_get_thread_num());
			
			//printf("sum odd : %d \n",odd_sum);
		}else{
			odd_sum += arr[i];
			printf("Thread Number: %d \n",omp_get_thread_num());
			
			//printf("sum even : %d \n",even_sum);
		}
	}
	printf("sum odd : %d \n",odd_sum);
	printf("sum even : %d \n",even_sum);
}
