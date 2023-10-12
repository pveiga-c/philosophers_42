/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:48:09 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/12 15:48:37 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void philo_eat(t_philo *philo)
{
    if(pick_up_fork(philo))
    {
        update_time(&philo->last_eat);
        philo->state = EAT;
        print_msg(philo, "is eating");
        philo->n_eaten++;
        drop_forks(philo);
    }
}

void philo_sleep(t_philo *philo)
{
    philo->state = SLEEP;
    print_msg(philo, "is sleeping");
}

void philo_think(t_philo *philo)
{
    philo->state = THINK;
    print_msg(philo, "is thinking");
}