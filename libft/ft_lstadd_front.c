/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:00:32 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 17:25:06 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adiciona o nó 'novo' no início da lista
*/
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst || !new)
		return ;
	aux = *lst;
	*lst = new;
	new->next = aux;
}
