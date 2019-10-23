#include<pthread.h>
#include<stdio.h>

void* print(void * s){
    int i;
    for(i = 0; i< 10 ; i++) 
        printf("%s",s);
}

int main() {
    pthread_t th1,th2,th3;
    int ret1,ret2,ret3;
    char s1[]  = "\n zdrasti 1 \n" ;
    char s2[]  = "\n zdrasti 2 \n" ;
    char s3[]  = "\n zdrasti 3 \n" ;
    ret1 = pthread_create(&th1,NULL, print,s1);
    ret2 = pthread_create(&th2,NULL, print,s2);
    ret3 = pthread_create(&th3,NULL, print,s3);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_join(th3,NULL);
    return 0;
}