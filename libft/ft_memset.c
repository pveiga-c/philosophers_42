/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *ft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:44:26 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/12 18:39:46 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função memset é usada para preencher um bloco 
de memória com um valor específico.
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*n_s;

	n_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		n_s[i] = c;
		i++;
	}
	return (n_s);
}
