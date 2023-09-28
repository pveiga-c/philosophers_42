/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/26 18:00:47 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    init_data(int ac, char **av, t_table *table)
{
    data->number_of_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        data->number_of_meals = ft_atoi(av[5]);
    else
        data->number_of_meals = -1;
    
}
void    alloc_philos(t_table *table)
{
    int i;

    i = 0;
    table->threads = malloc(sizeof(pthread_t) * *(table->number_of_philos + 1));
    if(!table->threads)
        error();
    table->philo = malloc(sizeof(t_philo *) * (table->number_of_philos + 1))
    while(i < table->number_of_philos)
    {
        table->philo[i] = malloc(t_philo);
        if(!table->philo)
            error();
        i++;
    }
}

int main (int ac, char **av)
{
    t_table table;
    
    if(check_args(ac, av) == 1)
        return (1);
    init_data(ac, av, &table);
    alloc_philos(&table);
    return (0);
}
    