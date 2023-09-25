/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:50:49 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 17:58:40 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função strrchr em C é usada para encontrar a última 
ocorrência de um caractere em uma string. Ela procura o 
caractere especificado na string de origem a partir do final 
da string e retorna um ponteiro para a posição onde o 
caractere foi encontrado pela última vez.
O tipo de retorno da função é um ponteiro para a posição onde
o caractere foi encontrado pela última vez na string de
origem. Se o caractere não for encontrado, a função retorna 
um ponteiro nulo.
A função strrchr é útil quando você precisa encontrar a 
última ocorrência de um caractere em uma string e trabalhar
 com a posição do caractere encontrado.
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}
