/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_and_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:23:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/23 21:13:12 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_costs(t_lst *a, t_lst *b)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->cost = get_cost(tmp->head, tmp->target, a, b);
		tmp = tmp->next;
	}
}

void	fill_target(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = *a;
	while (tmp)
	{
		tmp->target = get_target(b, tmp->head);
		tmp = tmp->next;
	}
}

void	move_the_cheapest(t_lst **a, t_lst **b)
{
	int	elem;

	elem = get_cheapest_move(*a);
	while ((*a)->head != elem)
	{
		if (get_direction(*a, elem))
			ra(a);
		else
			rra(a);
	}
	while ((*b)->head != (*a)->target)
	{
		if (get_direction(*b, (*a)->target))
			rb(b);
		else
			rrb(b);
	}
	pb(a, b);
}

int	get_direction(t_lst *lst, int elem)
{
	int		r;
	int		rr;
	t_lst	*tmp;

	r = 0;
	tmp = lst;
	while (tmp->head != elem)
	{
		r++;
		tmp = tmp->next;
	}
	rr = ft_lstsize(lst) - r;
	if (r < rr)
		return (1);
	return (0);
}
