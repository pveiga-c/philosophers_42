/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:08:22 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/11 18:28:50 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * Returns the current time in milliseconds since the Epoch.
 * 
 * @return The current time in milliseconds since the Epoch, or 0 if an error occurred.
 */
size_t get_time(void)
{
    struct timeval tv;
    
    if(gettimeofday(&tv, NULL))
        return (0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));     
}
/**
 * Mede o tempo decorrido durante um período especificado em microssegundos.
 *
 * @param data Ponteiro para a estrutura de dados que contém o período de sono.
 * @return Retorna o tempo decorrido em microssegundos durante o período de sono.
 */

size_t  passed_time(t_data *data)
{
    size_t start_time;
    size_t now;

    start_time = get_time();
    printf("s : %ld\n", start_time);
    usleep(data->time_to_die * 1000);
    printf("tt : %d\n", data->time_to_sleep);
    now = get_time();
    printf("n : %ld\n", now);

    return (now - start_time);
}
