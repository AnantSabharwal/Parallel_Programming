#include<stdio.h>
#include<omp.h>
#include<time.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertion_sort(int arr[], int n){
	for(int i=1;i<n;i++){
		j=i
		while (j>0 && arr[j-1]>arr[j]){
			swap(arr[j],arr[j-1]);
			j = j-1;
		}
	}
}
void quick_sort(int arr[], int low, int high){
	if(low<high){
		pi = partition(arr,low,high);
		quick_sort(arr,low,pi-1);
		quick_sort(arr,pi,high);
	}
}
void merge_sort(int arr[], int n){
	
}
int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the values of the array: \n");
	for (int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
}
