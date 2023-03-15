#include <stdio.h>
#include <omp.h>
#include <time.h>


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
  
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
  
// Driver program to test above functions
int main()
{
    int i, arr[10000];
    for (i = 0; i < 10000; i++) {
    arr[i] = rand();
	}	
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t start, end;
    start = clock();
    selectionSort(arr, n);
    end = clock();
    double t_seq, t_par;
    t_seq = (float)(end-start)/CLOCKS_PER_SEC;
    #pragma omp parallel
    start = clock();
    	selectionSort(arr, n);
    	//printf("Sorted array: \n");
    	//printArray(arr, n);
    end = clock();
    t_par = (float)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken seq: %f", t_seq);
    printf("\nTime Taken par: %f", t_par);
    printf("\nSpeedup: %f", t_seq/t_par);
    return 0;
}
