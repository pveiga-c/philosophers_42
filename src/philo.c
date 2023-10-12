/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:46:58 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/12 20:58:24 by pveiga-c         ###   ########.fr       */
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
    data->start_time = get_timestamp();
    pthread_mutex_init(&data->mutex_msg, NULL);
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

void    alloc_philos(t_data *data)
{
    int i;

    data->philo = malloc(sizeof(t_philo *) * data->number_of_philos + 1);
    if(!data->philo)
        write(1, "Malloc Error", 13);
    i = 0;
    while(i < data->number_of_philos)
    {
        data->philo[i] = malloc(sizeof(t_philo));
        if(!data->philo)
            write(1, "Malloc Error", 13);
        pthread_mutex_init(&data->philo[i]->mutex_philo, NULL);
        pthread_mutex_init(&data->philo[i]->mutex_life, NULL);
        data->philo[i]->id = i + 1;
        data->philo[i]->state = THINK; 
        data->philo[i]->fork = 1;
        data->philo[i]->n_eaten = 0; 
        data->philo[i]->data = data;
        data->philo[i]->id_left_philo = -1;
        id_left_philo(data->philo[i]); 
        i++;
        
    }
}

void    id_left_philo(t_philo *philo)
{
    if(philo->id == 1)
       philo->id_left_philo = philo->data->number_of_philos;
    else
        philo->id_left_philo = philo->id - 1;      
}
