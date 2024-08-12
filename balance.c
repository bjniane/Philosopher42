#include "philo.h"

int balance = 0;
pthread_mutex_t mutex;

int read_balance()
{
    usleep(250000);
    return (balance);
}

void    write_balance(int new_balance)
{
    usleep(250000);
    balance = new_balance;
}

void*   deposit(void *amount)
{
    pthread_mutex_lock(&mutex);
    int acount_balance = read_balance();

    acount_balance += *((int *) amount);
    write_balance(acount_balance);
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main()
{
    int before = read_balance();
    printf("before %d\n", before);

    // deposit(300);
    // deposit(200);

    pthread_t t1;
    pthread_t t2;

    pthread_mutex_init(&mutex, NULL);

    int deposit1 = 300;
    int deposit2 = 200;

    pthread_create(&t1, NULL, deposit, (void*) &deposit1);
    // pthread_join(t1, NULL);
    pthread_create(&t2, NULL, deposit, (void*) &deposit2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    int after = read_balance();
    printf("after %d\n", after);
}