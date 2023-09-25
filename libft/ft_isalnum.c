/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:36:18 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:31:40 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função isalnum em C é usada para determinar se um caractere 
é um caractere alfanumérico, ou seja, se ele é uma letra ou 
um dígito numérico. Ela retorna um valor inteiro diferente 
de zero se o caractere for alfanumérico e zero caso contrário.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}
