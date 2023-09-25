/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:34:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:32:16 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função isalpha em C é usada para determinar se um caractere
é uma letra do alfabeto. Ela retorna um valor inteiro 
diferente de zero se o caractere for uma letra e zero caso
contrário.
 */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return (1);
	}
	return (0);
}
