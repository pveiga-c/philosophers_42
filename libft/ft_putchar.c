/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:02:56 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 16:06:59 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Imprime um único caractere.
*/

#include "ft_printf.h"

void	ft_putchar(char c, int *len_final)
{
	write(1, &c, 1);
	*len_final += 1;
}
