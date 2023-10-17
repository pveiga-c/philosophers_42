/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/17 09:07:54 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"



void    print_msg(t_philo *philo, char *str)
{
    size_t time;

    time = get_timestamp() - philo->data->start_time;
    pthread_mutex_lock(&philo->data->mutex_msg);
    printf("%ld %d %s\n", time , philo->id, str);
    pthread_mutex_unlock(&philo->data->mutex_msg);

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
    //ft_free(&data);
       
    return (0);
}
    