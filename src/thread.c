/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:47:56 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/28 18:47:58 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    create_join_thread(t_table *table)
{
    int i;

    i = 0;
    while(i < table->number_of_philos)
    {
        if(pthread_create(&table->threads[i], NULL, &rotine_philo, NULL) != 0)
            perror("Failed to create thread");
        i++;
    }
    i = 0;
    while(i < table->number_of_philos)
    {
        if(pthread_join(table->threads[i], NULL) != 0)
            perror("Failed to join thread");
        i++;
    }
}

void    *rotine_philo(void *arg)
{
    printf("ola\n");
}
