/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_point_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:00:26 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/27 17:54:48 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_point_hexa(unsigned long int num, int *len_final)
{
	if (!num)
		ft_putstr("(nil)", len_final);
	else
	{
		if (num < 16)
		{
			ft_putstr("0x", len_final);
			ft_putchar(HEX_LOWER[num % 16], len_final);
			return ;
		}
		else
		{
			ft_put_point_hexa(num / 16, len_final);
			ft_putchar(HEX_LOWER[num % 16], len_final);
		}
	}
}
