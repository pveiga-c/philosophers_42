/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:08:22 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/12 21:17:39 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * Retorna a hora atual em milissegundos desde a Época.
 * 
 * @return O tempo atual em milissegundos desde a Época ou 0 se ocorreu um erro.
 */
size_t get_timestamp(void)
{
    struct timeval curr_time;
    
    if(gettimeofday(&curr_time, NULL))
        return (0);
    return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));     
}
/**
 * Mede o tempo decorrido durante um período especificado em microssegundos.
 *
 * @param data Ponteiro para a estrutura de dados que contém o período de sono.
 * @return Retorna o tempo decorrido em microssegundos durante o período de sono.
 */

size_t  passed_time(t_philo *philo)
{
    size_t start_time;
    size_t now;

    start_time = get_timestamp();
    usleep(philo->data->time_to_die * 1000);
    now = get_timestamp();
    return (now - start_time);
}

/**
 * Calcula o tempo decorrido desde o início da simulação.
 * 
 * @param philo Um ponteiro para a estrutura do filósofo.
 * @return O tempo decorrido em milissegundos.
 */
void update_time(size_t time)
{ 
    gettimeofday(&time, NULL);
}

void    ft_usleep(int milisec)
{
    struct timeval time;
    size_t start;
    size_t end;

    gettimeofday(&time, NULL);
    start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    end = start + milisec;
    while(start < end)
    {
        gettimeofday(&time, NULL);
        start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
        usleep(100);
    }
}
