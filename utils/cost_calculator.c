/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:48:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/22 14:59:43 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_maximum(t_lst *lst)
{
	int	max;

	max = lst->head;
	while (lst)
	{
		if (lst->head > max)
			max = lst->head;
		lst = lst->next;
	}
	return (max);
}

int	get_minimum(t_lst *lst)
{
	int	min;

	min = lst->head;
	while (lst)
	{
		if (lst->head < min)
			min = lst->head;
		lst = lst->next;
	}
	return (min);
}

int	get_target(t_lst *b, int elem)
{
	int		min;
	int		max;
	t_lst	*tmp;

	min = get_minimum(b);
	max = get_maximum(b);
	if (elem > max || elem < min)
		return (max);
	tmp = b;
	// with while (tmp && tmp->next) i got infinite loop
	// with while (tmp->next) i got infinite loop
	// with while (tmp) i got segfault on get_target, fill_target, universal_sort, push_swap, main
	while (tmp)
	{
		if (tmp->head > elem && tmp->next->head < elem)
			return (tmp->next->head);
		tmp = tmp->next;
	}
	return (max);
}
//TODO: Implement usage of rra and ra : for now calculating only with ra
//TODO: Implement usage of rrb and rb : for now calculating only with rb
int	get_cost(int elem, int target, t_lst *a, t_lst *b)
{
	t_lst	*tmp;
	int		cost;
	int		nb_ra;
	int		nb_rb;

	tmp = a;
	cost = 0;
	while (tmp->head != elem)
	{
		cost++;
		tmp = tmp->next;
	}
	nb_ra = cost;
	tmp = b;
	while (tmp->head != target)
	{
		cost++;
		tmp = tmp->next;
	}
	nb_rb = cost;
	return (cost);
}

int	get_cheapest_move(t_lst *a)
{
	int		elem;
	int		cost;
	t_lst	*tmp;

	elem = a->head;
	cost = a->cost;
	tmp = a;
	while (tmp)
	{
		if (tmp->cost < cost)
		{
			elem = tmp->head;
			cost = tmp->cost;
		}
		tmp = tmp->next;
	}
	return (elem);
}
