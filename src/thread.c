/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:56 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/05 14:49:06 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    create_join_thread(t_table *table)
{
    int i;

    i = 0;
    table.start_time = get_timestamp();
    while(i < table->number_of_philos)
    {
        if(pthread_create(&table->threads[i], NULL, &rotine_philo, NULL) != 0)
            perror("Failed to create thread");
        i++;
    }
    i = 0;
    while(i < table->number_of_philos)
    {
        if(pthread_join(table->threads[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
}

static void assingn_left_philo(t_table *table, t_philo *philo)
{
    if(philo->id == 0)
        philo->id_left_philo = table->philo[table->number_of_philos - 1]->id;
    else
        philo->id_left_philo = table->philo[philo->id - 1]->id;
}
void    eat(t_table *table, t_philo *philo)
{
    
}

void    sleep(t_table *table, t_philo *philo)
{
    
}
void    think(t_table *table, t_philo *philo)
{
    
}

void    *rotine_philo(void *arg)
{
    t_philo *philo;
    t_table *table;
    
    philo = (t_philo *)arg;
    table = philo->table;
    assingn_left_philo(table, philo);
    update_time(&philo->last_eat, NULL);
    if (!(philo->id % 2))
		usleep(100);
    while(1)
    {
        if(philo->state == THINK)
            eat(table, philo);
        if(philo->state == EAT)
            sleep(table, philo);
        if(philo->state == SLEEP)
            think(table, philo);
    }
    return (NULL);
}
