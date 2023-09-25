/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:06:47 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 16:30:38 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Itera a lista 'lst' e aplica a função
'f' no conteúdo de cada nó.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
