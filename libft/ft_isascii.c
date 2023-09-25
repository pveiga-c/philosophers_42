/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:36:51 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:32:14 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função isascii em C é usada para determinar se um valor 
inteiro representa um caractere ASCII válido. Ela retorna 
um valor inteiro diferente de zero se o valor estiver dentro
 do intervalo de valores ASCII, e zero caso contrário.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
