/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:08:47 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 16:20:57 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Imprime uma string (conforme definido pela convenção C comum).
*/

#include "ft_printf.h"

void	ft_putstr(char *str, int *len_final)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len_final);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len_final);
		i++;
	}
}
