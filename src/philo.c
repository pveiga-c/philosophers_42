/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:46:58 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/05 13:50:20 by pveiga-c         ###   ########.fr       */
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
    table->philo = (t_philo *)ft_calloc(sizeof(t_philo), table->number_of_philos);
    while(i < table->number_of_philos)
    {
        table->philo[i]->id = i;
        table->philo[i]->state = THINK;
    if (pthread_mutex_init(&(table->philo[i].mutex_eat_check), NULL) != 0)
			write (1, "Mutex error", 13);
		if (pthread_mutex_init(&(table->philo[i].mutex_life), NULL) != 0)
			write (1, "Mutex error", 13);
		i++;    
    }
}ypedef struct s_philo
{
	int				id;
	pthread_mutex_t	mutex;
	int				state;
	pthread_mutex_t		mutex_eat_check;
	pthread_mutex_t		mutex_life;
}                   t_p