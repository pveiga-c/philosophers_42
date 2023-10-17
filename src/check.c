/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:07:06 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/17 18:26:19 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

#include "../includes/philosophers.h"

int check_args(int ac, char **av)
{
    if(check_ac(ac) == 1)
        return (1);
    if(is_digit(ac, av) == 1)
        return (1);   
    if(check_av(ac, av) == 1)
        return (1);
    return (0);
}
/**
 * Verifica se o número de argumentos não é 5 ou 6.
 * 
 * Verifica o número de argumentos da linha de comando e exibe uma mensagem 
 * de ajuda, se necessário.
 *
 * @param ac Número de argumentos da linha de comando.
 * @return Retorna 0 se o número de argumentos estiver correto,
 *  1 se houver erro na quantidade de argumentos.
 * 
 */

int check_ac(int ac)
{
    if(ac < 5 || ac > 6)
    {
        ft_printf("Error: Wrong amount of arguments\n");
        ft_printf("./philo\n");
        ft_printf("[1] number_of_philosophers\n");
        ft_printf("[2] time_to_die\n");   
        ft_printf("[3] time_to_eat\n");   
        ft_printf("[4] time_to_sleep\n");   
        ft_printf("[5] [number_of_times_each_philosopher_must_eat]\n");    
        return (1);   
    }
    return (0);
}
/**
 * Verifica e valida os argumentos da linha de comando.
 *
 * @param ac Número de argumentos da linha de comando.
 * @param av Array de argumentos da linha de comando.
 * @return Retorna 0 se os argumentos são válidos, 1 se houver erros nos argumentos.
 * 
 * Converte os argumentos da linha de comando em variáveis inteiras.
 * Verifica se o argumento opcional está presente e, se sim, converte-o.
 * Verifica se os argumentos estão dentro dos limites aceitáveis.
 */


int check_av(int ac, char **av)
{
    int number_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
  
    number_of_philos = ft_atoi(av[1]);
    time_to_die = ft_atoi(av[2]);
    time_to_eat = ft_atoi(av[3]);
    time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
        number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        number_of_times_each_philosopher_must_eat = 0;
    if (number_of_philos < 1 || number_of_philos > 200 || time_to_die < 0
		|| time_to_eat < 0 || time_to_sleep < 0
		|| number_of_times_each_philosopher_must_eat < 0)
	{
		printf("Error: Invalid arguments\n");
        return (1);
    }
    return (0); 
}
/**
 * Verifica se todos os argumentos da linha de comando contêm apenas dígitos.
 *
 * @param ac Número de argumentos da linha de comando.
 * @param av Array de argumentos da linha de comando.
 * @return Retorna 0 se todos os argumentos contêm apenas dígitos, 1 se houver 
 * algum caractere não-dígito.
 */

int is_digit(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while(i < ac)
    {
        j = 0;
        while(av[i][j] != '\0')
        {
            if(av[i][j] < '0' || av[i][j] > '9')
            {
                ft_printf("ERROR :The arguments must be digits.\n");
                return (1);
            }
            j++;
        }
        i++;
    }
    return(0);
}

// void    print_data(t_data *data)
// {
//     int i;

//     i = 0;
//     printf("number of philos = %d\n", data->number_of_philos);
//     printf("time to die = %d\n", data->time_to_die);
//     printf("time to eat = %d\n", data->time_to_eat);
//     printf("time to sleep = %d\n", data->time_to_sleep);
//     printf("number of meals = %d\n", data->number_of_meals);
//     while(i < data->number_of_philos)
//     {
//         printf("id = %d\n", data->philo[i]->id);
//         printf("state = %d\n", data->philo[i]->state);
//         i++;      
//     }
// }