#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>

#define N 5;
#define THINKING 2;
#define HUNGRY 1;
#define EATING 0;