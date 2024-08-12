/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:35 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/11 22:49:28 by bjniane          ###   ########.fr       */
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
        ft_error("only positive numbers");
    if (!(str[i] >= '0' && str[i] <= '9'))
        ft_error("the input is not a correct digit");
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if ((result * sign) > INT_MAX)
        ft_error("the value is bigger than INT_MAX");
    return (result * sign);
}

void    ft_parsing(t_data *data, char **av)
{
    data->n_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (data->time_to_die < 60 || data->time_to_eat < 60
        || data->time_to_sleep < 60)
        ft_error("Use timestamps bigger than 60ms");
    if (av[5])
        data->n_times_to_eat = ft_atoi(av[5]);
    else
        data->n_times_to_eat = -1;
}