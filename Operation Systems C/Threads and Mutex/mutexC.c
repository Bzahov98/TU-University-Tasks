#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int counter;
pthread_mutex_t lock;

void* print_block(void* arg){
    pthread_mutex_lock(&lock);
    counter+=1;
    printf("\n Job started %d",counter);
    sleep(3);
    printf("\n Job finished%d ",counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void) {
    pthread_t first, second; 
    int err1, err2;
    
    err1 = pthread_create(&first,NULL,print_block,NULL);
    err1 = pthread_create(&second,NULL,print_block,NULL);

    pthread_join(first,NULL);
    pthread_join(second,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}