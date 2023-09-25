/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:38:47 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/13 17:58:58 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A função toupper em C é usada para converter um caractere 
para sua versão maiúscula. Ela retorna um caractere que 
representa a versão maiúscula do caractere especificado.
O tipo de retorno da função é um valor inteiro que representa
o caractere maiúsculo correspondente ao caractere 
especificado.
A função toupper converte o caractere especificado em sua 
versão maiúscula. Ela retorna um valor que representa o 
caractere maiúsculo correspondente ao caractere especificado.
A função toupper é útil quando você precisa converter um 
caractere para sua versão maiúscula antes de executar uma 
operação específica relacionada a caracteres maiúsculos ou 
minúsculos, como comparação de strings sem levar em conta o 
case das letras.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}
