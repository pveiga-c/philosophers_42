/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/05 13:42:41 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    start(t_table *table)
{
    mutex_init(&table); 
    thread_init(&table);
    create_join_thread(&table);
}
void    mutex_init(t_table *table)
{
    int i;
    
    i = 0;
    table->forks =(pthread_mutex_t *)(ft_calloc(sizeof(pthread_mutex_t), table->number_of_philos));
    while(i < table->number_of_philos)
    {
        if(pthread_mutex_init(&(table->forks[i]), NULL) != 0)
            perror("Mutex error");
        i++;
    }
}

void    thread_init(t_table *table)
{
    table->threads = (prhread_t *)ft_calloc(sizeof(prhread_t), table->number_of_philos);
    alloc_philos(&table);
}



int main (int ac, char **av)
{
    t_table table;
    
    if(check_args(ac, av) == 1)
        return (1);
    init_data(ac, av, &table);
    table.start_time = get_timestamp();
    start(&table);
    
    return (0);
}
    