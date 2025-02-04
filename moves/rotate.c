/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:56:52 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/03 12:08:34 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift up all elements of stack a by 1.
// The last element becomes the first one.
void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (!*a || ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = ft_lstlast(*a);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*b || ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = ft_lstlast(*b);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

// ra and rb at the same time.
void	rr(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*a || ft_lstsize(*a) < 2 || !*b || ft_lstsize(*b) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = tmp;
	last = ft_lstlast(last);
	last->next = tmp;
	tmp->next = NULL;
	tmp = *b;
	*b = (*b)->next;
	last = tmp;
	last = ft_lstlast(last);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rr\n", 3);
}
