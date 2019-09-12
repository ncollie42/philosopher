#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *testFunc2(void *input)
{
    int *num = malloc(sizeof(int));

    *num =5;
    for (int x = 0; x < 200; x++) {
        printf("me\n");       
    }
    return num;
}
void *testFunc(void *input)
{
    int *num = malloc(sizeof(int));

    *num =5;
    for (int x = 0; x < 100; x++) {
        printf("You\n");       
    }
    return num;
}

int main(void) {
    pthread_t t;
    pthread_t tt;
    int *num;
    pthread_create(&t, NULL, testFunc, NULL);
    pthread_create(&tt, NULL, testFunc2, NULL);
    pthread_join(t, (void*)&num);
    pthread_join(tt, (void*)&num);
    
    // pthread_detach(t);
    // pthread_detach(tt);
    printf("%d\n", *num);
}