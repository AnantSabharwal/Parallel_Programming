#include<stdio.h>
#include <math.h> 
#include<omp.h>
#include<time.h>
int fibonacci(int num){
	int prev2 = 0, prev1 = 1, current;
	for(int i = 2 ; i<num; i++){
		current = prev1 + prev2;
		prev2 = prev1;
		prev1 = current;
	}
	return current;
}

int main(){
	clock_t start, end;
	double t_seq, t_par;
	int arr[] = {10, 13, 5, 6};
	int i = 0;
	
	start = clock();
	for(i = 0; i<4; i++){
		printf("The %dth fibonacci number is: %d\n", arr[i], fibonacci(arr[i]) );
	}
	
	end = clock();
	t_seq = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("Time for sequential execution: %f\n", t_seq);
	
	
	start = clock();
	#pragma omp parallel for num_threads(4)
	for(i = 0; i<4; i++){
		printf("The %dth fibonacci number is: %d\n", arr[i], fibonacci(arr[i]) );
	}
	end = clock();
	t_par = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("Time for parallel execution: %f\n", t_par);
	
	double speedup = 0;
	speedup = t_seq/t_par;
	
	printf("Speed up: %f\n", speedup);
	
	double efficiency = 0;
	int num_threads = 4;
	efficiency = speedup/num_threads;
	printf("Efficiency: %f\n", efficiency); 
		
	return 0;
}
