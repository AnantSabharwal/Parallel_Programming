#include <stdio.h>
#include <omp.h>
#include<time.h>
#define N 1000

int main() {
    int i, sum = 0;
    double start_time, end_time;
    clock_t start, end;
    float t_seq;
    // Warm up to ensure that the parallel overhead is not included in the timing
    start = clock();
    for (i = 0; i < N; i++) {
        sum += i;
    }
    end = clock();
    t_seq = (float)(start-end);
    printf("Sequential time %f\n",t_seq);
    // Find sum of N numbers using critical section
    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        #pragma omp critical
        {
            sum += i;
        }
    }
    end_time = omp_get_wtime();
    printf("Sum using critical section: %d, Time: %f s\n", sum, end_time - start_time);
    
    // Find sum of N numbers using atomic
    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        #pragma omp atomic
        sum += i;
    }
    end_time = omp_get_wtime();
    printf("Sum using atomic: %d, Time: %f s\n", sum, end_time - start_time);
    
    // Find sum of N numbers using reduction
    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < N; i++) {
        sum += i;
    }
    end_time = omp_get_wtime();
    printf("Sum using reduction: %d, Time: %f s\n", sum, end_time - start_time);
    
    // Find sum of N numbers using master
    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp master
        {
            for (i = 0; i < N; i++) {
                sum += i;
            }
        }
    }
    end_time = omp_get_wtime();
    printf("Sum using master: %d, Time: %f s\n", sum, end_time - start_time);
    
    // Find sum of N numbers using locks
    sum = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);
    start_time = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        omp_set_lock(&lock);
        sum += i;
        omp_unset_lock(&lock);
    }
    end_time = omp_get_wtime();
    printf("Sum using locks: %d, Time: %f s\n", sum, end_time - start_time);
    omp_destroy_lock(&lock);
    
    return 0;
}


