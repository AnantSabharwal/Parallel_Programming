#include<stdio.h>
#include <math.h> 
#include<omp.h>
#include<time.h>

int main(){
	clock_t start, end;
	double t_seq, t_par;
	char str[] = "HeLLo", str1[] = "HeLLo";
	int len = 5, i = 0;
	
	start = clock();
	printf("Original string: %s\n", str);
	for(i = 0; i<len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] = str[i] - 32;
		}else if ( str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] + 32;
		}
	}
	printf("New string: %s\n", str);
	
	end = clock();
	t_seq = ((double) (end - start))/CLOCKS_PER_SEC;
	printf("Time for sequential execution: %f\n", t_seq);
	
	start = clock();
	printf("Original string: %s\n", str1);
	#pragma omp parallel num_threads(4)
	{
		int numthreads = omp_get_num_threads();
		int id = omp_get_thread_num();
		printf("Running thread %d\n", id);
		for(int i = id; i<len; i+=numthreads){
			if(str1[i] >= 'a' && str1[i] <= 'z'){
				str1[i] = str1[i] - 32;
			}else if ( str1[i] >= 'A' && str1[i] <= 'Z'){
				str1[i] = str1[i] + 32;
			}
		}
	}
	printf("New string: %s\n", str1);
	
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
