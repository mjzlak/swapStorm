/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:15:50 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/23 21:20:37 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_lst	*ft_lstnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->head = content;
	new->cost = 0;
	new->target = 0;
	new->next = NULL;
	return (new);
}
