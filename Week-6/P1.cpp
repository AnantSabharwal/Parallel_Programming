#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

void oddEvenSort(int *arr, int n) {
    int i, j, temp;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    	}
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            #pragma omp parallel for shared(arr) private(j, temp)
            for (j = 1; j < n; j += 2) {
                if (arr[j] < arr[j-1]) {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        } else { 
            #pragma omp parallel for shared(arr) private(j, temp)
            for (j = 2; j < n; j += 2) {
                if (arr[j] < arr[j-1]) {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
        cout<<endl<<i<<"	";
        for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    	}
    }
}

int main() {
    srand(time(NULL));
    int n = 10; 
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }
    double start = omp_get_wtime();
    oddEvenSort(arr, n);
    double end = omp_get_wtime();
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << end - start << " seconds" << endl;
    return 0;
}

