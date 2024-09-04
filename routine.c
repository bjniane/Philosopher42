/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 01:47:02 by bjniane           #+#    #+#             */
/*   Updated: 2024/09/04 02:40:29 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *msj)
{
	long	time;

	time = get_current_time() - philo->data->start_simulation;
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->end_simulation == false)
		printf("%ld %ld %s\n", time, philo->id, msj);
	pthread_mutex_unlock(&philo->data->mutex);
}

void	think(t_philo *philo)
{
	print(philo, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	print(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, "has taking a fork");
	if (philo->data->n_philo == 1)
	{
		ft_usleep(philo->data->time_to_die, philo);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taking a fork");
	print(philo, "is eating");
	pthread_mutex_lock(&philo->data->meals);
	philo->last_meal = get_current_time();
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->data->meals);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
