/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/11 20:09:23 by pveiga-c         ###   ########.fr       */
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

void    print_msg(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->data->mutex_msg);
    ft_printf("%d %s\n", philo->id, str);
    pthread_mutex_unlock(&philo->data->mutex_msg);

}

void    id_left_philo(t_philo *philo)
{
    if(philo->id == 1)
       philo->id_left_philo = philo->data->number_of_philos;
    else
        philo->id_left_philo = philo->id - 1;      
}

void    update_time(struct timeval *time)
{
    gettimeofday(time, NULL);
}


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


void    *routine_philo(void *arg)
{
    t_philo *philo;
    t_data  *data;
    
    philo = (t_philo *)arg;
    //update_time(&philo->last_eat);
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

void ft_free(t_data *data)
{
    int i = 0;
    
    while(i < data->number_of_philos)
        free(data->philo[i++]);
    free(data->philo);
}

int main (int ac, char **av)
{
    t_data data;
    int i;
    
    i= 0;
    
    if(check_args(ac, av) == 1)
        return (1);
    init_data(ac, av, &data);
    alloc_philos(&data);
    start(&data); 
    ft_free(&data);
       
    return (0);
}
    