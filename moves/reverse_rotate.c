/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:58:27 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/27 08:54:20 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_list **a)
{
	t_list	*last;
	t_list	*before_last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *a;
	*a = last;
}

// Shift down all elements of stack b by 1.
// The first element becomes the last one.
void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*before_last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *b;
	*b = last;
}

// rra and rrb at the same time.
void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}
