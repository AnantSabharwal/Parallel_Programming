#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void insertion_sort(int* arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void quick_sort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[right];
        arr[right] = temp;
        int mid = i+1;
        #pragma omp sections
        {
        	#pragma omp section
	        quick_sort(arr, left, mid-1);
	        #pragma omp section
	        quick_sort(arr, mid+1, right);
		}
    }
}

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void parallel_merge_sort(int* arr, int l, int r) {
    if (l < r) {
        if (r-l < 1000) {
            insertion_sort(arr+l, r-l+1);
            return;
        }
        int m = l + (r - l) / 2;
        #pragma omp sections
        {
            #pragma omp section
            parallel_merge_sort(arr, l, m);
            #pragma omp section
            quick_sort(arr, m+1, r);
        }
        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
	printf("The program has started running\n");
	int n;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 10)+1;
    }
    printf("Before \n");
    printArray(arr,n);
    omp_set_num_threads(2);
    double start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        parallel_merge_sort(arr, 0, n-1);
    }
    double end_time = omp_get_wtime();
    printf("Time taken: %lf seconds\n", end_time-start_time);
    printArray(arr,n);
    return 0;
}

