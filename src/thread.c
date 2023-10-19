/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:56 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/19 09:28:02 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	start(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (init_mutex(data) == 1)
	{
		printf("Error initializing mutexes\n");
		exit(4);
	}
	data->start_time = get_timestamp();
	while (i < data->number_of_philos)
	{
		pthread_create(&philo[i].thread, NULL, routine_philo, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	destroy_mutex(data);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->mutex_meal);
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_msg);
	i = 0;
	while (i < data->number_of_philos)
		pthread_mutex_destroy(&data->fork[i++].mutex_fork);
}

void	*routine_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->n_eaten != 0)
	{
		pthread_mutex_lock(&philo->data->mutex_dead);
		if (philo->data->dead == 0)
		{
			pthread_mutex_unlock(&philo->data->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->data->mutex_dead);
		if (philo_is_dead(philo) == 1)
			break ;
		if (philo->state == THINK)
			philo_eat(philo);
		else if (philo->state == EAT)
			philo_sleep(philo);
		else if (philo->state == SLEEP)
			philo_think(philo);
	}
	return (NULL);
}