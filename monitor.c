/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:40:45 by bjniane           #+#    #+#             */
/*   Updated: 2024/09/03 16:04:59 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_ate(t_data *data)
{
	long	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->full);
		if (data->philos[i].full == false)
		{
			pthread_mutex_unlock(&data->full);
			return (0);
		}
		pthread_mutex_unlock(&data->full);
		i++;
	}
	pthread_mutex_lock(&data->mutex);
	data->end_simulation = true;
	pthread_mutex_unlock(&data->mutex);
	return (1);
}

int	philo_dead(t_data *data)
{
	long	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->meals);
		if (get_current_time() - data->philos[i].last_meal >= data->time_to_die)
		{
			pthread_mutex_unlock(&data->meals);
			pthread_mutex_lock(&data->mutex);
			data->end_simulation = true;
			printf("%ld %ld died\n", get_current_time()
				- data->start_simulation, data->philos[i].id);
			pthread_mutex_unlock(&data->mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->meals);
		i++;
	}
	return (0);
}

void	*monitor(void *philo)
{
	t_data	*philos;

	philos = (t_data *)philo;
	while (1)
	{
		if (philo_dead(philos) == 1 || all_ate(philos) == 1)
			break ;
	}
	return (NULL);
}
