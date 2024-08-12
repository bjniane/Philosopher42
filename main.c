/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjniane <bjniane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 01:27:43 by bjniane           #+#    #+#             */
/*   Updated: 2024/08/11 01:49:46 by bjniane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 800 200 200 [5]

int main(int ac, char **av)
{
    t_data  data;

    if (ac == 5 || ac == 6)
    {
        //1) errors cheking
        ft_parsing(&data, av);
        
        //2) creating the actual things
        ft_init(&data);
    }
    else
    {
        ft_error("Wrong Input\n");
    }
}