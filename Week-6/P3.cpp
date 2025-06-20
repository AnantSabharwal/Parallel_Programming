#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define INTERVAL_START 5
#define INTERVAL_END 2500
#define NUM_THREADS 3

int main() {
    int sum = 0;
    double start_time, end_time;
    int chunk_size = (INTERVAL_END - INTERVAL_START + 1) / NUM_THREADS;

    omp_set_num_threads(NUM_THREADS);

    start_time = omp_get_wtime();
    for (int i = INTERVAL_START; i <= INTERVAL_END; i++) {
        sum += i;
    }
    end_time = omp_get_wtime();
    printf("Sequential Sum = %d, Time taken = %f seconds\n", sum, end_time - start_time);

    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(static, chunk_size) reduction(+:sum)
    for (int i = INTERVAL_START; i <= INTERVAL_END; i++) {
        sum += i;
    }
    end_time = omp_get_wtime();
    printf("Parallel Sum (Static Scheduling) = %d, Time taken = %f seconds\n", sum, end_time - start_time);

    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic, chunk_size) reduction(+:sum)
    for (int i = INTERVAL_START; i <= INTERVAL_END; i++) {
        sum += i;
    }
    end_time = omp_get_wtime();
    printf("Parallel Sum (Dynamic Scheduling) = %d, Time taken = %f seconds\n", sum, end_time - start_time);
    sum = 0;
    start_time = omp_get_wtime();
    #pragma omp parallel for schedule(guided, chunk_size) reduction(+:sum)
    for (int i = INTERVAL_START; i <= INTERVAL_END; i++) {
        sum += i;
    }
    end_time = omp_get_wtime();
    printf("Parallel Sum (Guided Scheduling) = %d, Time taken = %f seconds\n", sum, end_time - start_time);

    return 0;
}

