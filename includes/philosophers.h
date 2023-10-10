/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:30 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/10 18:07:26 by pveiga-c         ###   ########.fr       */
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

typedef struct s_philo t_philo;

typedef struct s_data
{
	int			number_of_philos;
	int			time_to_die;
	int 		time_to_eat;
	int			time_to_sleep;
	int			number_of_meals;
	pthread_mutex_t	mutex_msg;
	t_philo		**philo;
	pthread_t 	*thread;
}					t_data;

struct s_philo
{
	t_data			*data;
	int				id;
	int				fork;
	int				n_eaten;
	int				id_left_philo;
	pthread_mutex_t	mutex_philo;
	int				state;
	struct timeval	last_eat;
};

/****************philosophers***********************/

int 	main (int ac, char **av);
void    init_data(int ac, char **av, t_data *data);

/*******************check***************************/

int 	check_args(int ac, char **av);
int 	check_ac(int ac);
int 	check_av(int ac, char **av);
int 	is_digit(int ac, char **av);
void    print_data(t_data *data);

/*******************check***************************/

void    	alloc_philos(t_data *data);
void    	start(t_data *data);
void    	*routine_philo(void *arg);
size_t 		get_time(void);
size_t  	passed_time(t_data *data);

/*******************forks***************************/

int 	pick_up_fork(t_data *data, t_philo *philo);
int 	pick_up_left(t_data *data, t_philo *philo);
int 	pick_up_right(t_data *data, t_philo *philo);

/*******************forks***************************/

void    start(t_data *data);
void    print_msg(t_data *data, t_philo *philo, char *str);
void    id_left_philo(t_data *data, t_philo *philo);
void    start_time(struct timeval *time);
void 	philo_eat(t_data *data, t_philo *philo);
void 	philo_sleep(t_data *data, t_philo *philo);
void 	philo_think(t_data *data, t_philo *philo);
void    *routine_philo(void *arg);

#endif 