#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex;

void* thread(void* arg){
    //wait
    sem_wait(&mutex);
    printf("\nEntered..\n");
    // critical section
    sleep(4);
    //signal
    printf("\n just Exiting..");
    sem_post(&mutex);
}

int main() {
    sem_init(&mutex, 0 , 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    sleep(2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}