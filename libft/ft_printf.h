/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:09:16 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/28 17:06:05 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len_final);
void	ft_putstr(char *str, int *len_final);
void	ft_put_point_hexa(unsigned long int num, int *len_final);
void	ft_putnbr(int nbr, int *len_final);
void	ft_put_unsig_dec(unsigned int nbr, int *len_final);
void	ft_put_nbr_lower(unsigned int num, int *len_final);
void	ft_put_nbr_upper(unsigned int num, int *len_final);

#endif