/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:08:22 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/14 16:55:52 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


size_t get_timestamp(void)
{
    struct timeval curr_time;
    
    if(gettimeofday(&curr_time, NULL))
        return (0);
    return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));     
}

void    ft_usleep(int time, t_philo *philo)
{
    size_t start;
   
    start = get_timestamp();
	while ((get_timestamp() - start) < time)
		usleep(50);
}
