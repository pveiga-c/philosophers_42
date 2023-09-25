/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:15:03 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:41:18 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função strdup em C é usada para criar uma cópia de uma 
string. Ela aloca memória suficiente para armazenar a cópia 
da string e copia o conteúdo da string original para a nova 
memória alocada. 
O tipo de retorno da função é um ponteiro para a nova string,
 que é uma cópia da string original.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
