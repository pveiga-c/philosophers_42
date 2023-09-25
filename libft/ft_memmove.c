/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:47:24 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 16:50:16 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função memmove é semelhante à função memcpy, mas ela 
é projetada para lidar com a sobreposição de memória. 
Quando a área de origem e a área de destino se sobrepõem,
a função memcpy pode não copiar os dados corretamente, 
mas a função memmove garantirá que os dados sejam copiados
corretamente, independentemente da sobreposição de memória.
*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s)
		return (d);
	if (d < s)
		return (ft_memcpy(dest, src, n));
	while (n--)
		d[n] = s[n];
	return (d);
}
