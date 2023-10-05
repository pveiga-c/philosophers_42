/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:30 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/05 14:41:42 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

# define DEAD	0
# define EAT	1
# define THINK	2
# define SLEEP	3


typedef struct s_table
{
	pthread_t		*threads;
	t_philo			**philo;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	long			start_time;
	pthread_mutex_t	*forks;
}					t_table;

typedef struct s_philo
{
	t_table			*table;
	int				id;
	int				id_left_philo;
	int				state;
	struct timeval	last_eat;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_eat_check;
	pthread_mutex_t	mutex_life;
}                   t_philo;
/****************philosophers***********************/

int 	main (int ac, char **av);
void    init_data(int ac, char **av, t_table *data);

/*******************check***************************/

int 	check_args(int ac, char **av);
int 	check_ac(int ac);
int 	check_av(int ac, char **av);
int 	is_digit(int ac, char **av);


void 	create_join_thread(t_table *table);
void    alloc_philos(t_table *table);
void    *rotine_philo(void *arg);

/*******************time***************************/

void	ft_usleep(int milisec);
time_t	get_time(t_table *table);
time_t	get_timestamp(void);

#endif 