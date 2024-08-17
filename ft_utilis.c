/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:48 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/17 06:06:36 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_error(const char *str)
{
    printf("%s\n", str);
    exit(1);
}

long    get_current_time(void)
{
    struct timeval  time;
    
    if (gettimeofday(&time, NULL) == -1)
        ft_error("gettimeofday error");
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int check_end(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex);
    if (philo->data->end_simulation == true)
    {
        pthread_mutex_unlock(&philo->data->mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->mutex);
    return (0);
}

void    ft_usleep(long time, t_philo *philo)
{
    long    start;
    
    start = get_current_time();
    while (get_current_time() - start < time && check_end(philo) == 0)
        usleep(500);
}