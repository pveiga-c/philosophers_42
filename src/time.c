/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:08:22 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/05 14:33:20 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void	ft_usleep(int milisec)
// {
// 	struct timeval	time_v;
// 	long int		start;
// 	long int		end;

// 	gettimeofday(&time_v, NULL);
// 	start = (time_v.tv_sec * 1000) + (time_v.tv_usec / 1000);
// 	end = start + milisec;
// 	while (start < end)
// 	{
// 		gettimeofday(&time_v, NULL);
// 		start = (time_v.tv_sec * 1000) + (time_v.tv_usec / 1000);
// 		usleep(100);
// 	}
// }

// time_t	get_time(t_table *table)
// {
// 	struct timeval	curr_time;

// 	gettimeofday(&curr_time, 0);
// 	return ((curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000) \
// 	- table->start_time);
// }

// time_t	get_timestamp(void)
// {
// 	struct timeval	curr_time;

// 	gettimeofday(&curr_time, 0);
// 	return ((curr_time.tv_sec * 1000l + curr_time.tv_usec / 1000l));
// }

void	update_time(struct timeval *time, pthread_mutex_t *mutex)
{
	if (mutex)
	{
		pthread_mutex_lock(mutex);
		gettimeofday(time, NULL);
		pthread_mutex_unlock(mutex);
	}
	else
		gettimeofday(time, NULL);
}