#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
char* sieve;
long long num;
 

void* sieve_step(void* i_void) {
    long long i = *(long long*)i_void;
    for (long long j = i * i; j <= num; j += i) {
        sieve[j] = 1;
    }
    pthread_exit(NULL);
}
 
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Syntax: ./out Number_of_threads Number_for_test\n");
        exit(1);
    }
    int threads_num = atoi(argv[1]);
    num = atoi(argv[2]);
 
 
    pthread_t* threads = (pthread_t*)calloc(threads_num, sizeof(pthread_t));
    if (threads == NULL) {
        printf("Can't allocate space for threads\n");
        exit(2);
    }
 
   
    long long* args = (long long*)malloc(threads_num* sizeof(long long));
    if (args == NULL) {
        printf("Can't create an array for arguments for threads\n");
        exit(3);
    }
    

    sieve = (char*)calloc((num + 1), sizeof(char));
    if (sieve == NULL) {
        printf("Can't create an array for sieve\n");
        exit(3);
    }
 

    sieve[0] = 1;
    sieve[1] = 1;
 
    int cur_thread = 0; 
    for (long long i = 2; i * i <= num; ++i) {
        if (sieve[i] == 1) { 
            continue;
        }
        if (cur_thread >= threads_num) {
            
            pthread_join(threads[cur_thread % threads_num], NULL);
        }
 
        args[cur_thread % threads_num] = i; 
        pthread_create(&threads[cur_thread % threads_num], NULL, sieve_step, &args[cur_thread % threads_num]);
        ++cur_thread;
    }
 

    for (int i = 0; i < threads_num; ++i) {
        pthread_join(threads[i], NULL);
    }
 
    if (sieve[num] == 1) {
        printf("%lld is not a prime number\n", num);
    }
    else {
        printf("%lld is a prime number\n", num);
    }
 
    free(sieve);
    free(threads);
    free(args);
}