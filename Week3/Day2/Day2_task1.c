#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define N 2000000000

long sum1(long *a, long n) {
    long sum = 0;
    for (long i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

long sum4(long *a, long n) {
    long s0 = 0, s1 = 0, s2 = 0, s3 = 0;
    for (long i = 0; i < n; i += 4) {
        s0 += a[i + 0];
        s1 += a[i + 1];
        s2 += a[i + 2];
        s3 += a[i + 3];
    }
    return s0 + s1 + s2 + s3;
}


int main() {
    long *a = malloc(N * sizeof(long));
    for (long i = 0; i < N; i++) {
        a[i] = rand() % 100;
    }

    double start_time =  clock();
    long sum1_result = sum1(a, N);
    double end_time = clock();
    printf("sum1 result: %ld, time taken: %f seconds\n", sum1_result, (end_time - start_time) / CLOCKS_PER_SEC);


    double start_time_4 =  clock();
    long sum4_result = sum4(a, N);
    double end_time_4 = clock();
    printf("sum4 result: %ld, time taken: %f seconds\n", sum4_result, (end_time_4 - start_time_4) / CLOCKS_PER_SEC);

}