/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:48:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/23 21:06:03 by mloeffer         ###   ########.fr       */
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

int	get_target(t_lst **b, int elem)
{
	int		min;
	int		max;
	t_lst	*tmp;

	min = get_minimum(*b);
	max = get_maximum(*b);
	if (elem > max || elem < min)
		return (max);
	tmp = *b;
	while (tmp)
	{
		if (!tmp->next)
		{
			if (tmp->head > elem && (*b)->head < elem)
				return ((*b)->head);
		}
		if (tmp->next && tmp->head > elem && tmp->next->head < elem)
			return (tmp->next->head);
		tmp = tmp->next;
	}
	return (max);
}

int	get_cost(int elem, int target, t_lst *a, t_lst *b)
{
	int		cost_a;
	int		cost_b;
	t_lst	*tmp;

	cost_a = 0;
	cost_b = 0;
	tmp = a;
	while (tmp && tmp->head != elem)
	{
		cost_a++;
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp && tmp->head != target)
	{
		cost_b++;
		tmp = tmp->next;
	}
	if (!get_direction(a, elem))
		cost_a = ft_lstsize(a) - cost_a;
	if (!get_direction(b, target))
		cost_b = ft_lstsize(b) - cost_b;
	return (cost_a + cost_b);
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
