/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:07:06 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/25 19:07:32 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_args(int ac, char **av)
{
    if(check_ac(ac) == 1)
        return (1);
    if(is_digit(ac, av) == 1)
        return (1);   
    if(check_av(ac, av) == 1)
        return (1);
    return (0);
}

int check_ac(int ac)
{
    if(ac < 5 || ac > 6)
    {
        ft_printf("Error: Wrong amount of arguments\n");
        ft_printf("./philo\n");
        ft_printf("[1] number_of_philosophers\n");
        ft_printf("[2] time_to_die\n");   
        ft_printf("[3] time_to_eat\n");   
        ft_printf("[4] time_to_sleep\n");   
        ft_printf("[5] [number_of_times_each_philosopher_must_eat]\n");    
        return (1);   
    }
    return (0);
}

int check_av(int ac, char **av)
{
    int number_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
  
    number_of_philos = ft_atoi(av[1]);
    time_to_die = ft_atoi(av[2]);
    time_to_eat = ft_atoi(av[3]);
    time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        number_of_times_each_philosopher_must_eat = 0;
    if (number_of_philos < 1 || number_of_philos > 200 || time_to_die < 0
		|| time_to_eat < 0 || time_to_sleep < 0
		|| number_of_times_each_philosopher_must_eat < 0)
	{
		printf("Error: Invalid arguments\n");
        return (1);
    }
    ft_printf("%d\n", number_of_philos);
    ft_printf("%d\n", time_to_die);
    ft_printf("%d\n", time_to_eat);
    ft_printf("%d\n", time_to_sleep);
    ft_printf("%d\n", number_of_times_each_philosopher_must_eat);
    return (0);
}

int is_digit(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = 0;
        while(av[i][j] != '\0')
        {
            if(av[i][j] < '0' || av[i][j] > '9')
            {
                ft_printf("ERROR :The arguments must be digits.\n");
                return (1);
            }
            j++;
        }
        i++;
    }
    return(0);
}