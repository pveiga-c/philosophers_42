/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:22:16 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 17:06:11 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_nbr_upper(unsigned int num, int *len_final)
{
	if (num >= 16)
		ft_put_nbr_upper(num / 16, len_final);
	ft_putchar(HEX_UPPER[num % 16], len_final);
}
