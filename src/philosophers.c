/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/10 19:28:11 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    start(t_data *data)
{
    int i;

    i = 0;
    while(i < data->number_of_philos)
    {
        pthread_create(&data->thread[i], NULL, &routine_philo, data->philo[i]);        
        i++;
    }
    i = 0;
    while(i < data->number_of_philos)
    {
        pthread_join(data->thread[i], NULL);        
        i++;
    }
}

void    print_msg(t_data *data, t_philo *philo, char *str)
{
    pthread_mutex_lock(&data->mutex_msg);
    ft_printf("%ld %d %s\n", passed_time, philo->id, str);
    pthread_mutex_unlock(&data->mutex_msg);

}

void    id_left_philo(t_data *data, t_philo *philo)
{
    if(philo->id == 0)
       philo->id_left_philo = data->philo[data->number_of_philos - 1]->id;
    else
        philo->id_left_philo = data->philo[philo->id - 1]->id;        
}
void    start_time(struct timeval *time)
{
    gettimeofday(time, NULL);
}


void philo_eat(t_data *data, t_philo *philo)
{
    if(pick_up_fork(data, philo))
    {
        philo->state = EAT;
        print_msg(data, philo, "is eating");
        philo->n_eaten++;
    }
}

void philo_sleep(t_data *data, t_philo *philo)
{
    philo->state = SLEEP;
    print_msg(data, philo, "is sleeping");
}

void philo_think(t_data *data, t_philo *philo)
{
    philo->state = THINK;
    print_msg(data, philo, "is thinking");
}


void    *routine_philo(void *arg)
{
    t_philo *philo;
    t_data  *data;
    
    philo = (t_philo *)arg;
    id_left_philo(data, philo);
    start_time(&philo->last_eat);
    while(1)
    {
        if(philo->state == THINK)
            philo_eat(data, philo);
        if(philo->state == EAT)
            philo_sleep(data, philo);
        else if(philo->state == SLEEP)
            philo_think(data, philo);
    }
    return (NULL);
}



int main (int ac, char **av)
{
    t_data data;
    
    if(check_args(ac, av) == 1)
        return (1);
    init_data(ac, av, &data);
    alloc_philos(&data);
    start(&data);    
    return (0);
}
    