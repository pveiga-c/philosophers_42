/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:08:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/05/01 11:15:01 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkafter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_print(char *str, va_list arg, int i, int *len)
{
	if (str[i] == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (str[i] == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (str[i] == 'p')
		ft_put_point_hexa(va_arg(arg, unsigned long int), len);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(arg, long int), len);
	else if (str[i] == 'u')
		ft_put_unsig_dec(va_arg(arg, unsigned int), len);
	else if (str[i] == 'x')
		ft_put_nbr_lower(va_arg(arg, unsigned int), len);
	else if (str[i] == 'X')
		ft_put_nbr_upper(va_arg(arg, unsigned int), len);
	else if (str[i] == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_checkafter(str[i + 1]) == 1)
		{
			ft_print((char *)str, arg, i + 1, &len);
			i++;
		}
		else if (str[i] != '%')
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(arg);
	return (len);
}

/*
int	main(void)
{
	int	nbr;

	char	c;
	char	*str;
	char	*p;
	str = "Ola, bom dia!";
	nbr = 456;
	p = NULL;
	c = 'd';

	printf("-----PRINTF-----\n");
	printf("C = %c\nS = %s\n", c, str);
	printf("P = %p\n", p);
	printf("P =%p\n", str);
	printf("percent = %%\n");
	printf("num(d) = %d\n", nbr);
	printf("num(i) = %i\n", nbr);
	printf("num(u) = %u\n", nbr);
	printf("P = %x\n", nbr);
	printf("P = %X\n", nbr);
	ft_printf("\n-----FT_PRINTF-----\n");
	ft_printf("C = %c\nS = %s\n", c, str);
	ft_printf("P = %p\n", p);
	ft_printf("P =%p\n", str);
	ft_printf("percent = %%\n");
	ft_printf("num(d) = %d\n", nbr);
	ft_printf("num(i) = %i\n", nbr);
	ft_printf("num(u) = %u\n", nbr);
	ft_printf("P = %x\n", nbr);
	ft_printf("P = %X\n", nbr);
	ft_printf("\n");
}*/
