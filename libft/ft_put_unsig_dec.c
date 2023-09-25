/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsig_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:09:31 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 16:55:59 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsig_dec(unsigned int nbr, int *len_final)
{
	if (nbr >= 10)
		ft_put_unsig_dec(nbr / 10, len_final);
	ft_putnbr(nbr % 10, len_final);
}
