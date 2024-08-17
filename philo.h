/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:55 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/17 09:38:33 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>

// ./philo 5 800 200 200 [5]

typedef struct s_data   t_data;

typedef struct s_philo
{
    pthread_t   th;
    int     id;
    long    meals_counter; // meals eaten depent on aarg nb 5;
    long    last_meal; //last meal eaten
    bool    full;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    t_data  *data;
}   t_philo;

typedef struct  s_data
{
    long    n_philo;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    n_times_to_eat; //[5] flag if -1
    long    start_simulation; 
    bool    end_simulation; //for a philo dies or all philos full;
    pthread_mutex_t mutex;
    pthread_mutex_t meals;
    pthread_mutex_t full;
    pthread_mutex_t *forks; //array to forks;
    t_philo *philos; //array of philos
}   t_data;

void    ft_error(const char *str);
void    ft_parsing(t_data *data, char **av);
void    *routine(void *philo);
int     creat_threads(t_data *data);
long    get_current_time(void);
void    ft_usleep(long time, t_philo *philo);
void    print(t_philo *philo, char *msj);
void    think(t_philo *philo);
void    ft_sleep(t_philo *philo);
void    eat(t_philo *philo);
void    ft_init(t_data *data);
void    clean(char *str, t_data *data);
void    *monitor(void *philo);

# endif