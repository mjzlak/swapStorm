/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:58:27 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/16 22:55:00 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_lst **a)
{
	t_lst	*last;
	t_lst	*before_last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last)
		before_last->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

// Shift down all elements of stack b by 1.
// The first element becomes the last one.
void	rrb(t_lst **b)
{
	t_lst	*last;
	t_lst	*before_last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last)
		before_last->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

// rra and rrb at the same time.
void	rrr(t_lst **a, t_lst **b)
{
	t_lst	*last_a;
	t_lst	*last_b;
	t_lst	*before_last;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	last_a = *a;
	last_b = *b;
	while (last_a->next)
	{
		before_last = last_a;
		last_a = last_a->next;
	}
	last_a->next = *a;
	*a = last_a;
	while (last_b->next)
	{
		before_last = last_b;
		last_b = last_b->next;
	}
	if (before_last)
		before_last->next = NULL;
	last_b->next = *b;
	*b = last_b;
	write(1, "rrr\n", 4);
}
