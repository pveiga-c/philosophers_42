/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:12:31 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 17:50:52 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função memcmp em C é usada para comparar 
dois blocos de memória.
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		{
			i++;
		}
		else if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		else if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
	}
	return (0);
}
