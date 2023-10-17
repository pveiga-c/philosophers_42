/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:56 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/17 09:26:49 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    start(t_data *data)
{
    int i;

    i = 0;
    data->start_time = get_timestamp();
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
    
    philo = (t_philo *)arg;
   //data->start_time = get_timestamp();
   //if(philo->id % 2 == 0)
    //        sleep(100);
    while(!philo->data->dead)
    {
        if(philo->state == THINK)
            philo_eat(philo);
        if(philo_is_dead(philo))
            return (NULL);
        else if(philo->state == EAT)
            philo_sleep(philo);
        //if(philo_is_dead(philo))
        //    break;
        else if(philo->state == SLEEP)
            philo_think(philo);
       // if(philo_is_dead(philo))
        //    break;
    }
    return (NULL);
}