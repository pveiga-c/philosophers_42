/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:39:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 17:06:18 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_nbr_lower(unsigned int num, int *len_final)
{
	if (num >= 16)
		ft_put_nbr_lower(num / 16, len_final);
	ft_putchar(HEX_LOWER[num % 16], len_final);
}
