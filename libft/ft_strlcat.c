/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:48:53 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:41:16 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função strcat em C é usada para concatenar duas strings. 
Ela adiciona a string de origem ao final da string de destino,
substituindo o caractere nulo de terminação da string de
destino pelo primeiro caractere da string de origem.
O tipo de retorno da função é um ponteiro para a string de 
destino. A string de destino deve ter espaço suficiente 
para armazenar a string de origem concatenada, incluindo 
o caractere nulo de terminação.
A função strcat é útil quando você precisa adicionar uma 
string a outra, sem criar uma nova string.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
