/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:37:33 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:32:50 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função isprint em C é usada para determinar se um caractere
é um caractere imprimível, ou seja, se ele é um caractere 
que pode ser exibido na tela. Ela retorna um valor inteiro 
diferente de zero se o caractere for imprimível e zero caso
contrário.
*/

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
