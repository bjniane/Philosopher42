/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:35 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/17 03:02:18 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int    ft_atoi(char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
        ft_error("Error\nonly positive numbers");
    if (!(str[i] >= '0' && str[i] <= '9'))
        ft_error("Error\nthe input is not a correct digit");
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if ((result * sign) > INT_MAX)
        ft_error("Error\nthe value is bigger than INT_MAX");
    return (result * sign);
}

void    ft_parsing(t_data *data, char **av)
{
    data->n_philo = ft_atoi(av[1]);
    if (data->n_philo > 200 || data->n_philo == 0)
        ft_error("Error\nUse a number ranging from 1 to 200\n");
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (data->time_to_die < 60 || data->time_to_eat < 60
        || data->time_to_sleep < 60)
        ft_error("Error\nUse timestamps bigger than 60ms");
    if (av[5])
    {
        data->n_times_to_eat = ft_atoi(av[5]);
        if (data->n_times_to_eat == 0)
            ft_error("Error\nUse another time bigger than 0");
    }
    else
        data->n_times_to_eat = -1;
}
