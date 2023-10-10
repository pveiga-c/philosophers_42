/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/10 17:43:14 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int pick_up_left(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_philo);
    pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
    if(philo->fork == 1 && data->philo[philo->id_left_philo]->fork == 1)
    {
        philo->fork--;
        data->philo[philo->id_left_philo]->fork--;
        pthread_mutex_lock(&philo->mutex_philo);
        pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
        print_msg(data, philo, "has taken a fork");
        return (1);
    }
    pthread_mutex_lock(&philo->mutex_philo);
    pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
    return (0);
}

int pick_up_right(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
    pthread_mutex_lock(&philo->mutex_philo);
    if(philo->fork == 1 && data->philo[philo->id_left_philo]->fork == 1)
    {
        philo->fork--;
        data->philo[philo->id_left_philo]->fork--;
        pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
        pthread_mutex_lock(&philo->mutex_philo);
         print_msg(data, philo, "has taken a fork");
        return (1);
    }
    pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
    pthread_mutex_lock(&philo->mutex_philo);
    return (0);
}

int pick_up_fork(t_data *data, t_philo *philo)
{
    if(philo->id % 2 == 0)
    {
        if(pick_up_left(data, philo))
            return (1);
    }
    else
    {
        if(pick_up_right(data, philo))
            return (1);
    }
    return (0);
}