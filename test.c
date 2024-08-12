#include "philo.h"
int count = 0;
pthread_mutex_t mutex;
void    *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        count++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int ac, char **av)
{
    pthread_t   t1;
    pthread_t   t2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    printf("count is : %d\n", count);
    return (0);
}