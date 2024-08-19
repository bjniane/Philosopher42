#include "philo.h"

//This test for deadlock

pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *thread1()
{
    pthread_mutex_lock(&lock1);
    printf("thread 1 aquired lock1\n");
    sleep(1);
    pthread_mutex_lock(&lock2);
    printf("thread 1 aquired lock 2\n");
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return (NULL);
}

void    *thread2()
{
    pthread_mutex_lock(&lock2);
    printf("thread 2 aquired lock 2\n");
    sleep(1);
    pthread_mutex_lock(&lock1);
    printf("thread 2 aquired lock 1\n");
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return (NULL);
}

int main()
{
    pthread_t   t1, t2;
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    printf("done\n");
    return (0);
}
