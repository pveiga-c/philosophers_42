/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:48:09 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/14 17:07:31 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void philo_eat(t_philo *philo)
{
    if(pick_up_fork(philo))
    {
        philo->state = EAT;
        print_msg(philo, "is eating");
        pthread_mutex_lock(&philo->data->mutex);
        philo->last_eat = get_timestamp() + philo->data->start_time;
        philo->time_of_life = philo->last_eat + philo->data->time_to_die;
        pthread_mutex_unlock(&philo->data->mutex);
        ft_usleep(philo->data->time_to_eat, philo);
        pthread_mutex_lock(&philo->data->mutex);
        philo->n_eaten++;
        pthread_mutex_unlock(&philo->data->mutex);
        drop_forks(philo);
    }
}

void philo_sleep(t_philo *philo)
{
    philo->state = SLEEP;
    print_msg(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep, philo);
}

void philo_think(t_philo *philo)
{
    philo->state = THINK;
    print_msg(philo, "is thinking");
}

int philo_is_dead(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex);
    if(philo->data->dead == 1)
    {
        pthread_mutex_unlock(&philo->data->mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->mutex);
    return (0);
}