/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:03:34 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 15:05:45 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *len_final)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", len_final);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', len_final);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, len_final);
	ft_putchar(nbr % 10 + '0', len_final);
}
