#include <stdio.h>
#include <omp.h>
#include<time.h>
#define N 20

int main() {
    int i;
    long long fact = 1;
    double start_time, end_time;
    clock_t start,end;
    
    // Warm up to ensure that the parallel overhead is not included in the timing
    printf("Sequential Execution\n");
    start = clock();
    for (i = 1; i <= N; i++) {
        fact *= i;
    }
    end = clock();
    printf("Sequential Execution time: %f\n",(float)(end-start));
    
    // Find factorial of N numbers using critical section
    fact = 1;
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 2; i <= N; i++) {
        #pragma omp critical
        {
            fact *= i;
        }
    }
    end_time = omp_get_wtime();
    printf("Factorial using critical section: %lld, Time: %f s\n", fact, end_time - start_time);
    
    // Find factorial of N numbers using atomic
    fact = 1;
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 2; i <= N; i++) {
        #pragma omp atomic
        fact *= i;
    }
    end_time = omp_get_wtime();
    printf("Factorial using atomic: %lld, Time: %f s\n", fact, end_time - start_time);
    
    // Find factorial of N numbers using reduction
    fact = 1;
    start_time = omp_get_wtime();
    #pragma omp parallel for reduction(*:fact)
    for (i = 2; i <= N; i++) {
        fact *= i;
    }
    end_time = omp_get_wtime();
    printf("Factorial using reduction: %lld, Time: %f s\n", fact, end_time - start_time);
    
    // Find factorial of N numbers using master
    fact = 1;
    start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (i = 2; i <= N; i++) {
                fact *= i;
            }
        }
    }
    end_time = omp_get_wtime();
    printf("Factorial using master: %lld, Time: %f s\n", fact, end_time - start_time);
    
    // Find factorial of N numbers using locks
    fact = 1;
    omp_lock_t lock;
    omp_init_lock(&lock);
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 2; i <= N; i++) {
        omp_set_lock(&lock);
        fact *= i;
        omp_unset_lock(&lock);
    }
    end_time = omp_get_wtime();
    printf("Factorial using locks: %lld, Time: %f s\n", fact, end_time - start_time);
    omp_destroy_lock(&lock);
    
    return 0;
}


