#include "philo.h"

static void philo_init(t_data *data)
{
    int i;
    t_philo *philo;

    i = -1;
    while (++i < data->n_philo)
    {
        philo = data->philos + i;
        philo->id = i + 1;
        philo->full = false;
        philo->meals_counter = 0;
        philo->r_fork = &data->forks[(i + 1) % data->n_philo];
        philo->l_fork = &data->forks[i];
        if (data->philos->id % 2)
        {
            philo->r_fork = &data->forks[i];
            philo->l_fork = &data->forks[(i + 1) % data->n_philo];
        }
    }
}

void    ft_init(t_data *data)
{
    int i;

    i = -1;
    data->end_simulation = false;
    data->philos = malloc(sizeof(t_philo) * data->n_philo);
    if (!(data->philos))
        return (NULL);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    if (!data->forks)
        return (NULL);
    while (++i < data->n_philo)
        pthread_mutex_init(&data->forks[i], NULL);
    philo_init(data);

}