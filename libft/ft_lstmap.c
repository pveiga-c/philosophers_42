/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:57:06 by correia           #+#    #+#             */
/*   Updated: 2023/04/24 16:31:00 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Itera a lista 'lst' e aplica a função
'f' no conteúdo de cada nó. Cria um novo
lista resultante das sucessivas aplicações de
a função 'f'. A função 'del' é usada para
exclua o conteúdo de um nó, se necessário.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst->next;
	}
	return (new);
}
