/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:42:12 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 18:04:52 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*A função tolower em C é usada para converter um caractere
para sua versão minúscula. Ela retorna um caractere que 
representa a versão minúscula do caractere especificado.
O tipo de retorno da função é um valor inteiro que representa
 o caractere minúsculo correspondente ao caractere 
 especificado.
A função tolower converte o caractere especificado em sua 
versão minúscula. Ela retorna um valor que representa o 
caractere minúsculo correspondente ao caractere especificado.
A função tolower é útil quando você precisa converter um 
caractere para sua versão minúscula antes de executar uma 
operação específica relacionada a caracteres maiúsculos ou 
minúsculos, como comparação de strings sem levar em conta o 
case das letras.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}
