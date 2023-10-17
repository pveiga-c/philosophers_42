/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:46:58 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/17 19:26:05 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * Inicializa a estrutura de dados com valores dos 
 * argumentos da linha de comando.
 *
 * @param ac Número de argumentos da linha de comando.
 * @param av Array de argumentos da linha de comando.
 * @param data Ponteiro para a estrutura t_data que será inicializada.
 */

void    init_data(int ac, char **av, t_data *data)
{
    data->number_of_philos = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        data->number_of_meals = ft_atoi(av[5]);
    else
        data->number_of_meals = -1;
    data->dead = 1;
}

/**
 * Aloca memória dinamicamente para as estruturas de filósofos e threads.
 * @param data Ponteiro para a estrutura de dados que contém informações 
 * sobre os filósofos.
 * Aloca memória para o array de threads com base no número de filósofos.
 * Aloca memória para o array de estruturas t_philo com base no número 
 * de filósofos.
 * Inicializa os campos da estrutura t_philo para cada filósofo.
 */

void    alloc_philos(t_data *data, t_philo *philo)
{
    int i;
  
    i = 0;
    while(i < data->number_of_philos)
    {
        
        philo[i].id = i + 1;
        philo[i].state = THINK; 
        philo[i].n_eaten = data->number_of_meals ; 
        philo[i].data = data;
        philo[i].last_eat = get_timestamp();
        philo[i].left_fork = philo[i].id - 1;
        philo[i].right_fork = (philo[i].id) % data->number_of_philos;
        i++;   
    }
}
int init_mutex(t_data *data)
{
    int i;
    if(pthread_mutex_init(&data->mutex_msg, NULL))
        return (1);
    if(pthread_mutex_init(&data->mutex_meal, NULL))
        return (1);
    if(pthread_mutex_init(&data->mutex_dead, NULL))
        return (1);
    data->fork = malloc(sizeof(t_fork) * (data->number_of_philos));
    if(!data->fork)
    {
        write(1, "Malloc Error", 13);
        exit(1);
    }
    i = 0;
    while(i < data->number_of_philos)
    {
        data->fork[i].aval = 1;
        if(pthread_mutex_init(&data->fork[i].mutex_fork, NULL))
            return (1);
        i++;
    } 
    return(0);
}
