/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:21:45 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/16 22:50:09 by mloeffer         ###   ########.fr       */
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

t_lst	*ft_lstlast(t_lst *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

size_t  ft_lstsize(t_lst *lst)
{
	size_t  size;

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

t_lst	*ft_lstnew(int content)
{
    t_lst	*new;

    new = malloc(sizeof(t_lst));
    if (!new)
        return (NULL);
    new->content = content;
    new->cost = 0;    // Initialiser les nouveaux champs
    new->target = 0;  // Initialiser les nouveaux champs
    new->next = NULL;
    return (new);
}

void	ft_lstdelone(t_lst *lst)
{
    if (!lst)
        return ;
    // Ne pas libérer lst->content car c'est maintenant un int stocké directement
    free(lst);
}