/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:57:28 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/25 11:26:15 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta função escreve a string s no descritor de arquivo fd seguido por um 
'\n'para criar uma nova linha. Essa função é exatamente igual à nossa função 
 ft_putendl, exceto pelo fato de recebermos um parâmetro para o descritor de 
 arquivo. Usaremos nossas funções ft_putstr_fd e ft_putchar_fd para fazer esta 
 função funcionar. Revise ft_putstr_fd e ft_putchar_fd para entender o 
 funcionamento interno desta função.
 */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
