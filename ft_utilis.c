/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:48 by bjniane           #+#    #+#             */
/*   Updated: 2024/09/04 02:42:10 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("gettimeofday error"), 1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if (philo->data->end_simulation == false)
	{
		pthread_mutex_unlock(&philo->data->mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (1);
}

void	ft_usleep(long time, t_philo *philo)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < time && !check(philo))
		usleep(500);
}
