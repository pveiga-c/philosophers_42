/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:48:13 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:27:40 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função ft_split tem como objetivo dividir uma string em um array de strings
 com base em um caractere delimitador fornecido como argumento. A função retorna 
 um ponteiro para um array de ponteiros de caracteres, em que cada ponteiro de
  caracteres aponta para uma substring da string original.
*/

#include "libft.h"
#include <stdio.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

static int	ft_len_word(char *s, char c)
{
	int	i;
	int	n_word;

	i = 0;
	n_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n_word++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n_word);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**matrix;

	matrix = (char **)malloc(sizeof(char *) * (ft_len_word((char *)s, c) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			matrix[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	matrix[k] = NULL;
	return (matrix);
}
/*
int	main(void)
{
	char	str[100];
	char	**s1;
	int		i;
	int		j;

	str[100] = {"^^^1^^2a,^^^^3^^^^--h^^^^"};
	i = 0;
	j = ft_len_word(str, '^');
	s1 = ft_split(str, '^');
	while (s1[i] != NULL && i != j)
	{
		printf("%s\n", s1[i]);
		i++;
	}
	free(s1);
	return (0);
}*/
