/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:02:01 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/04/24 17:27:50 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exclui e libera o nó fornecido e cada sucessor desse nó,
usando a função 'del' e free(3).
Finalmente, o ponteiro para a lista deve ser definido
como NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*content;

	while (*lst)
	{
		content = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = content;
	}
	*lst = NULL;
}
