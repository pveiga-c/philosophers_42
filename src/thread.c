/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:56 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/12 21:02:53 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    start(t_data *data)
{
    int i;

    i = 0;
    while(i < data->number_of_philos)
    {
        pthread_create(&data->philo[i]->thread, NULL, &routine_philo, data->philo[i]);        
        i++;
    }
    i = 0;
    while(i < data->number_of_philos)
    {
        pthread_join(data->philo[i]->thread, NULL);        
        i++;
    }
}

void    *routine_philo(void *arg)
{
    t_philo *philo;
    t_data  *data;
    
    philo = (t_philo *)arg;
    while(1)
    {
        if(philo->state == THINK)
            philo_eat(philo);
        else if(philo->state == EAT)
            philo_sleep(philo);
        else if(philo->state == SLEEP)
            philo_think(philo);
    }
    return (NULL);
}