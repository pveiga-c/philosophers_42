/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:13:28 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 17:46:48 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função strnstr em C é semelhante à função strstr, mas com 
a adição de um parâmetro adicional que especifica o número 
máximo de caracteres que serão pesquisados na string de 
origem. Ela procura a substring especificada na string de 
origem e retorna um ponteiro para a posição onde a substring
foi encontrada pela primeira vez, desde que a substring 
esteja contida nos primeiros n caracteres da string de origem.
O tipo de retorno da função é um ponteiro para a posição onde
a substring foi encontrada pela primeira vez na string de 
origem. Se a substring não for encontrada ou se não for
encontrada nos primeiros n caracteres da string de origem, 
a função retorna um ponteiro nulo.
A função strnstr é útil quando você precisa encontrar a 
primeira ocorrência de uma substring em uma string, mas quer 
limitar a pesquisa a um número máximo de caracteres na string 
de origem.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && big[i + j] != '\0')
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
