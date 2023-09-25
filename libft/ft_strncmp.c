/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:52:12 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 16:13:03 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função strncmp em C é semelhante à função strcmp, mas com a 
adição de um terceiro argumento que especifica o número 
máximo de caracteres que serão comparados entre as duas 
strings. Ela compara os caracteres das duas strings 
lexicograficamente até um máximo de n caracteres e retorna 
um valor inteiro que indica a relação entre as duas strings.
O tipo de retorno da função é um valor inteiro que indica a 
relação entre as duas strings:
-Se as duas strings forem iguais até os primeiros n 
caracteres, a função retorna 0.
-Se a primeira string for maior que a segunda string até os 
primeiros n caracteres, a função retorna um valor maior que 0.
-Se a primeira string for menor que a segunda string até os 
primeiros n caracteres, a função retorna um valor menor que 0.
A função strncmp é útil quando você precisa comparar apenas 
um número limitado de caracteres entre duas strings para 
determinar se elas são iguais ou qual é a ordem lexicográfica 
entre elas.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
