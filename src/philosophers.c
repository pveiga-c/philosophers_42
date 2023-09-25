/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/25 16:59:07 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_ac(int ac)
{
    if(ac < 5 || ac > 6)
    {
        ft_printf("Error: Wrong amount of arguments\n");
        ft_printf("./philo ");
        ft_printf("number_of_philosophers ");
        ft_printf("time_to_die ");   
        ft_printf("time_to_eat ");   
        ft_printf("time_to_sleep ");   
        ft_printf("[number_of_times_each_philosopher_must_eat]");   
        return (1);   
    }
    return (0);
}

int check_av(int ac, char **av)
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

    if(!isdigit(ac, av))
        return (1);    
    number_of_philosophers = ft_atoi(av[1]);
    time_to_die = ft_atoi(av[2]);
    time_to_eat = ft_atoi(av[3]);
    time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        number_of_times_each_philosopher_must_eat = -1;
    return (0);
}

int isdigit(int ac, char **av)
{
    if(av[1])
}

int main (int ac, char **av)
{
    if(check_ac(ac))
        return(1);
    if(check_av(ac, av))
        return (1);
    return (0);
}