#include<stdio.h>
#include<omp.h>
#include<time.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int n)
{
    int i, j, min;
  
    // One by one move boundary of unsorted subarray
    #pragma omp parallel for shared(min) private(i,j)
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;
  
        // Swap the found minimum element with the first element
           if(min != i)
            swap(&arr[min], &arr[i]);
            printf("thread number: %d \n",omp_get_thread_num());
    }
}
int main(){
	printf("Enter size of the array\n");
	int n;
	scanf("%d",&n);
	printf("\nEnter the inputs : \n");
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	//int arr[] = {64, 25, 12, 22, 11};
	
	selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
