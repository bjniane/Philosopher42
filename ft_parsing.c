/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:35 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/30 20:42:49 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

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
			return (1);
		if ((isdigit(av[i])) && av[i + 1] == '+')
			return (1);
		if (av[i] == '+' && (isdigit(av[i + 1])))
			i++;
		if (!(isdigit(av[i])))
			return (1);
		i++;
	}
	return (0);
}

int	ft_parsing(t_data *data, char **av)
{
	if (check(av[1]) || check(av[2]) || check(av[3]) || check(av[4]))
		return (printf("Error\nInvalid input\n"), 1);
	data->n_philo = ft_atoi(av[1]);
	if (data->n_philo > 200 || data->n_philo == 0)
		return (printf("Error\nUse a number ranging from 1 to 200\n"), 1);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60)
		return (printf("Error\nUse timestamps bigger than 60ms"), 1);
	if (av[5])
	{
		if (check(av[5]))
			return (printf("Error\nInvalid input\n"), 1);
		data->n_times_to_eat = ft_atoi(av[5]);
		if (data->n_times_to_eat == 0)
		{
			printf("Error\nUse another number of times to eat bigger than 0");
			return (1);
		}
	}
	else
		data->n_times_to_eat = -1;
	return (0);
}
