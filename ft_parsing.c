/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:35 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/19 00:34:49 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int  isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

static long    ft_atoi(char *str)
{
    int i;
    int sign;
    long result;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

static int	check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
        if (av[i] == '-')
            ft_error("Eroor\nOnly positive numbers\n");
        if (av[i] == '+' && (isdigit(av[i - 1])))
            return (0);
        if (av[i] == '+' && (isdigit(av[i + 1])))
            i++;
        if (ft_atoi(&av[i]) > INT_MAX)
            ft_error("Error\nthe value is bigger than INT_MAX");
		if (!(isdigit(av[i])))
			return (0);
		i++;
	}
	return (1);
}

void    ft_parsing(t_data *data, char **av)
{
    if (!check(av[1]) || !check(av[2]) || !check(av[3]) || !check(av[4]))
        ft_error("Error\nInvalid input\n");
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
        if (!check(av[5]))
            ft_error("Error\nInvalid input\n");
        data->n_times_to_eat = ft_atoi(av[5]);
        if (data->n_times_to_eat == 0)
            ft_error("Error\nUse another time bigger than 0");
    }
    else
        data->n_times_to_eat = -1;
}
