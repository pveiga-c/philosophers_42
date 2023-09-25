/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:09:18 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 15:35:05 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta função aloca memória e retorna uma string 'nova' de caracteres
terminado com um '\0' que é o char equivalente ao int passado no parâmetro. 
Números negativos também devem ser gerenciados. Se a alocação falhar, a função 
retornará NULL.
*/

#include "libft.h"
#include <stdio.h>

int	ft_len_num(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -1 * n;
		i++;
	}
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	else
		i = 1;
	return (i);
}

static char	*ft_put_word(long int n, int i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -1 * n;
	}
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len_num(n);
	str = ft_put_word(n, i);
	return (str);
}
/*
int	main(void)
{
	int		n = -2147483648;
	char	*s;

	s = ft_itoa(n);
	printf("%s\n", s);
	return (0);
}*/
