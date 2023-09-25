/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:34 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:32:40 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função isdigit em C é usada para determinar se um caractere
é um dígito numérico. Ela retorna um valor inteiro diferente
de zero se o caractere for um dígito e zero caso contrário.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
