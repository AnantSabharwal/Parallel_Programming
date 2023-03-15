#include <stdio.h>
#include <omp.h>
#include <time.h>

int main() {
  	int size, key, i, index;
  	printf("Number of elements in the list: ");
  	scanf("%d", &size);
  
	int arr[size];
	for (i = 0; i < size; i++) {
    arr[i] = rand();
	}
	
	clock_t start, end;
	double t_seq, t_par;
	
  	printf("Enter the element to search ie. key element: ");
  	scanf("%d", &key);
  	
  	// Sequential
  	start = clock();
  	for (index = 0; index < size; index++)
    	if (arr[index] == key)
      		break; 
	end = clock();
	t_seq = (float)(end-start)/CLOCKS_PER_SEC;
	
	// Parallel
	start = clock();
  	#pragma omp parallel for
  	for (index = 0; index < size; index++)
    	if (arr[index] == key)
      		printf("Thread %d found the key element at index %d\n", omp_get_thread_num(), index);
	end = clock();
	t_par = (float)(end-start)/CLOCKS_PER_SEC;
//  	if (index < size) 
//    	printf("Key element found at index %d", index);
//  	else
//    	printf("Key element not found");
    	
    printf("Time taken seq: %f", t_seq);
    printf("\nTime taken par: %f", t_par);
    printf("\nSpeedup: %f", t_seq/t_par);

  return 0;
}
