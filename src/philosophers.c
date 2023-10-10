/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/10 09:25:07 by correia          ###   ########.fr       */
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
    
    //print_data(data);
   //printf("time to sleep: %ld\n", passed_time(data));
}
void    id_left_philo(t_data *data, t_philo *philo)
{
    if(philo->id == 1)
        philo->id_left_philo = data->philo[data->number_of_philos]->id;
    else
        philo->id_left_philo = data->philo[philo->id - 1]->id;        
}
void    start_time(struct timeval *time)
{
    gettimeofday(time, NULL);
}
void pick_up_left(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_philo);
    pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
    if(philo->fork == 1 && data->philo[philo->id_left_philo]->data == 1)
    {
        philo->fork--;
        data->philo[philo->id_left_philo]->fork--;
        pthread_mutex_lock(&philo->mutex_philo);
        pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
        print_msg();
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
    if(philo->fork == 1 && data->philo[philo->id_left_philo]->data == 1)
    {
        philo->fork--;
        data->philo[philo->id_left_philo]->fork--;
        pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
        pthread_mutex_lock(&philo->mutex_philo);
        print_msg();
        return (1);
    }
    pthread_mutex_lock(&data->philo[philo->id_left_philo]->mutex_philo);
    pthread_mutex_lock(&philo->mutex_philo);
    return (0);
}

int pick_up_fork(t_data *data, t_philo *philo)
{
    if(philo->id % 2 == 0)
        pick_up_left(data, philo);
    else
        pick_up_right(data, philo);
}

void philo_eat(t_data *data, t_philo *philo)
{
    if(pick_up_fork(data, philo))
    {
        philo->state = EAT;
        printf(print_msg());
        philo->n_eaten++;
    }
}

void philo_sleep(t_data *data, t_philo *philo)
{
    philo->state = SLEEP;
    print_msg();
}

void philo_think(t_data *data, t_philo *philo)
{
    philo->state = THINK;
    print_msg();
}


void    *routine_philo(void *arg)
{
    t_philo *philo;
    t_data  *data;
    
    philo = (t_philo *)arg;
    data = philo->data;
    it_left_philo(data, philo);
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
    