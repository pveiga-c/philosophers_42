/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:08:22 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/10 09:25:38 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * Returns the current time in milliseconds since the Epoch.
 * 
 * @return The current time in milliseconds since the Epoch, or 0 if an error occurred.
 */
__uint64_t get_time(void)
{
    struct timeval tv;
    
    if(gettimeofday(&tv, NULL))
        return (0);
    return ((tv.tv_sec * (__uint64_t)1000) + (tv.tv_sec / 1000));     
}
/**
 * Mede o tempo decorrido durante um período especificado em microssegundos.
 *
 * @param data Ponteiro para a estrutura de dados que contém o período de sono.
 * @return Retorna o tempo decorrido em microssegundos durante o período de sono.
 */

__uint64_t  passed_time(t_data *data)
{
    __uint64_t start_time;
    __uint64_t  now;

    start_time = get_time();
    usleep(data->time_to_sleep);
    now = get_time();
    return (now - start_time);
}
