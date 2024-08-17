#include "philo.h"

static void philo_init(t_data *data)
{
    long    i;

    i = 0;
    while (i < data->n_philo)
    {
        data->philos[i].id = i + 1;
        data->philos[i].data = data;
        data->philos[i].full = false;
        data->philos[i].meals_counter = 0;
        data->philos[i].last_meal = get_current_time();
        data->philos[i].r_fork = &data->forks[(i + 1) % data->n_philo];
        data->philos[i].l_fork = &data->forks[i];
        if (data->philos->id % 2 == 0)
        {
            data->philos[i].r_fork = &data->forks[i];
            data->philos[i].l_fork = &data->forks[(i + 1) % data->n_philo];
        }
        i++;
    }
}

void    ft_init(t_data *data)
{
    long    i;

    i = 0;
    data->end_simulation = false;
    data->philos = malloc(sizeof(t_philo) * data->n_philo);
    if (!(data->philos))
        ft_error("Failed alocation for philos\n");
    data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    if (!data->forks)
    {
        free(data->philos);
        ft_error("Failed allocation for forks\n");
    }
    pthread_mutex_init(&data->mutex, NULL);
    pthread_mutex_init(&data->meals, NULL);
    pthread_mutex_init(&data->full, NULL);
    while (i < data->n_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    philo_init(data);
}
