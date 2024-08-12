/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:55 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/11 22:49:45 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>

typedef struct s_philo
{
    int     id;
    long    meals_counter;
    long    last_meal_time;
    bool    full;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
}   t_philo;

typedef struct  s_data
{
    pthread_t   thread;
    long    n_philo;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    n_times_to_eat; //[5] flag if -1
    long    start_simulation; 
    bool    end_simulation; //for a philo dies or all philos full;
    pthread_mutex_t *forks; //array to forks;
    t_philo *philos;
}   t_data;

void    ft_error(const char *str);
void    ft_parsing(t_data *data, char **av);

# endif