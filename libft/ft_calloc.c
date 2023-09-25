/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:11:41 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 18:26:10 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função calloc é uma função da linguagem de 
programação C que é usada para alocar espaço na
 memória para um determinado número de elementos 
 de um determinado tamanho e inicializar esses 
 elementos com valor zero.
 */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;

	str = malloc(nmemb * size);
	if (str == NULL)
	{
		return (0);
	}
	ft_bzero(str, nmemb * size);
	return (str);
}
