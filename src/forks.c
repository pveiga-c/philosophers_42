/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/12 15:41:46 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int pick_up_left(t_philo *philo)
{
    int i;

    i = philo->id_left_philo - 1;
    pthread_mutex_lock(&philo->mutex_philo);
    pthread_mutex_lock(&philo->data->philo[i]->mutex_philo);
    if(philo->fork == 1 && philo->data->philo[i]->fork == 1)
    {
        philo->fork--;
        (philo->data->philo[i]->fork)--;
        pthread_mutex_unlock(&philo->mutex_philo);
        pthread_mutex_unlock(&philo->data->philo[i]->mutex_philo);
        print_msg(philo, "has taken a fork");
        print_msg(philo, "has taken a fork");
        return (1);
    }
    pthread_mutex_unlock(&philo->mutex_philo);
    pthread_mutex_unlock(&philo->data->philo[i]->mutex_philo);
    return (0);
}

int pick_up_right(t_philo *philo)
{
    int i;

    i = philo->id_left_philo - 1;
    pthread_mutex_lock(&philo->data->philo[i]->mutex_philo);
    pthread_mutex_lock(&philo->mutex_philo);
    if(philo->fork == 1 && philo->data->philo[i]->fork == 1)
    {
        philo->fork--;
        (philo->data->philo[i]->fork)--;
        pthread_mutex_unlock(&philo->data->philo[i]->mutex_philo);
        pthread_mutex_unlock(&philo->mutex_philo);
        print_msg(philo, "has taken a fork");
        print_msg(philo, "has taken a fork");
        
        return (1);
    }
    pthread_mutex_unlock(&philo->data->philo[i]->mutex_philo);
    pthread_mutex_unlock(&philo->mutex_philo);
    return (0);
}

int pick_up_fork(t_philo *philo)
{
    if(philo->id % 2 == 0)
    {
        if(pick_up_left(philo))
            return (1);
    }
    else
    {
        if(pick_up_right(philo))
            return (1);
    }
    return (0);
}

void    drop_forks(t_philo *philo)
{
    if(philo->id % 2 == 0)
    {
       int i;

        i = philo->id_left_philo - 1;
        pthread_mutex_lock(&philo->mutex_philo);
        pthread_mutex_lock(&philo->data->philo[i]->mutex_philo);
        philo->fork++;
        (philo->data->philo[i]->fork)++;
        pthread_mutex_unlock(&philo->mutex_philo);
        pthread_mutex_unlock(&philo->data->philo[i]->mutex_philo);   
    }
    else
    {
       int i;

        i = philo->id_left_philo - 1;
        pthread_mutex_lock(&philo->data->philo[i]->mutex_philo);
        pthread_mutex_lock(&philo->mutex_philo);
        philo->fork++;
        (philo->data->philo[i]->fork)++;
        pthread_mutex_unlock(&philo->data->philo[i]->mutex_philo);
        pthread_mutex_unlock(&philo->mutex_philo);
    }
}