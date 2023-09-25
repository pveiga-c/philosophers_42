/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:51:42 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/09 15:28:26 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função recebe duas strings como entrada: s1 e s2.
Ela aloca dinamicamente memória para uma nova 
string que conterá a concatenação das duas strings
de entrada.
A função então copia o conteúdo da primeira string 
(s1) para a nova string e, em seguida, copia o 
conteúdo da segunda string (s2) para a nova string 
imediatamente após o conteúdo da primeira string. 
A nova string resultante é retornada pela função.
*/

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
