/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:06:25 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/20 15:26:00 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta função aplica a função de parâmetro f a cada caractere de uma string
também passou em seu parâmetro precisamente na posição da string de índice 
desse caractere. Cada caractere que é passado para a função f é modificado se
necessário.
O objetivo dessa função é percorrer a string "s" e para cada caractere 
encontrado, chamar a função "f" passando como primeiro argumento o índice 
do caractere na string e como segundo argumento um ponteiro para esse caractere.
 */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
