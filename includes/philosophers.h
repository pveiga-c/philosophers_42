/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:30 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/26 17:51:26 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <threads.h>
#include "../libft/libft.h"

typedef struct s_philo
{
	int				id;
	t_table			*table
}                   t_philo;

typedef struct s_table
{
	pthread_t		*threads;
	t_philo			**philo;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
    t_philo         *philo;
}					t_table;

/****************philosophers***********************/

int main (int ac, char **av);
void    init_data(int ac, char **av, t_data *data);

/*******************check***************************/

int check_args(int ac, char **av);
int check_ac(int ac);
int check_av(int ac, char **av);
int is_digit(int ac, char **av);

#endif 