/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:46:58 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/28 18:47:39 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    init_data(int ac, char **av, t_table *table)
{
    table->number_of_philos = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        table->number_of_meals = ft_atoi(av[5]);
    else
        table->number_of_meals = -1;
    
}

void    alloc_philos(t_table *table)
{
    int i;

    i = 0;
    table->threads = malloc(sizeof(pthread_t) * (table->number_of_philos + 1));
    if(!table->threads)
        perror("Failed to create thread");
    table->philo = malloc(sizeof(t_philo *) * (table->number_of_philos + 1));
    while(i < table->number_of_philos)
    {
        table->philo[i] = malloc(sizeof(t_philo));
        if(!table->philo)
            perror("Failed to create thread");
        i++;
    }
}
