/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:21:45 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/23 21:17:19 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t	ft_lstsize(t_lst *lst)
{
	size_t	size;

	size = 0;
	if (!lst)
		return (size);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstdelone(t_lst *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	free_list(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	ft_lstclear(t_lst **lst)
{
	t_lst	*current;
	t_lst	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current);
		current = next;
	}
	*lst = NULL;
}
