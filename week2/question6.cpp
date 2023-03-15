#include<stdio.h>
#include <math.h> 
#include<omp.h>
#include<time.h>

int isprime(int num){
	for(int i = 2; i<= (int)sqrt(num); i++){
		if(num%i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	clock_t start, end;
	double t_seq, t_par;
	int first = 2, last = 20;
	int i = 0;
	
	start = clock();
	for(i = first; i<=last; i++){
		if(isprime(i)){
			printf("%d ", i);
		}
	}
	printf("\n");
	
	end = clock();
	t_seq = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("Time for sequential execution: %f\n", t_seq);
	
	
	start = clock();
	
	#pragma omp parallel for num_threads(4)
	for(i = first; i<=last; i++){
		if(isprime(i)){
			printf("%d ", i);
		}
	}
	printf("\n");
	
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
