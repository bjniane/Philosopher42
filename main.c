/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:43 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/18 09:54:10 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 800 200 200 [5]

void    clean(char *str, t_data *data)
{
    long    i;

    i = 0;
    if (str)
        printf("%s\n", str);
    pthread_mutex_destroy(&data->mutex);
    pthread_mutex_destroy(&data->meals);
    pthread_mutex_destroy(&data->full);
    while (i < data->n_philo)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    free(data->philos);
    free(data->forks);
}

int check_full(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->full);
    if (philo->data->n_times_to_eat != -1 && philo->meals_counter >= philo->data->n_times_to_eat)
    {
        philo->full = true;
        pthread_mutex_unlock(&philo->data->full);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->full);
    return (0);
}

void    *routine(void *philo)
{
    t_philo *philos;

    philos = (t_philo *)philo;
    if (philos->id % 2 == 0)
        ft_usleep(60, philos);
    pthread_mutex_lock(&philos->data->mutex);
    while (philos->data->end_simulation == false)
    {
        pthread_mutex_unlock(&philos->data->mutex);
        eat(philos);
        if (check_full(philo)) //TO UPDATE after sleeping
            return (NULL);
        ft_sleep(philos);
        think(philos);
        pthread_mutex_lock(&philos->data->mutex);
    }
    pthread_mutex_unlock(&philos->data->mutex);
    
    return (NULL);
}

int creat_threads(t_data *data)
{
    long    i;

    i = -1;
    data->start_simulation = get_current_time();
    while (++i < data->n_philo)
    {
        if (pthread_create(&data->philos[i].th, NULL, &routine, &data->philos[i]) != 0)
            clean("Error\nThread creation failed\n", data);
    }
    monitor(data);
    i = -1;
    while (++i < data->n_philo)
    {
        if (pthread_join(data->philos[i].th, NULL) != 0)
            clean("Error\nThread join failed\n", data);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_data  data;

    if (ac != 5 && ac != 6)
        ft_error("Error\nInvalid numbers of arguments\n");
    else
    {
        memset(&data, 0, sizeof(t_data));
        ft_parsing(&data, av);
        ft_init(&data);
        creat_threads(&data);
        clean(NULL, &data); //TODO
    }
    return (0);
}