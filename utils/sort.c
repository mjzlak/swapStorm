/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:31 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/23 21:12:18 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort_three(t_lst **a)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*a)->head;
	val2 = (*a)->next->head;
	val3 = (*a)->next->next->head;
	if (val1 > val2 && val2 < val3 && val1 < val3)
		sa(a);
	else if (val1 > val2 && val2 > val3)
	{
		sa(a);
		rra(a);
	}
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		ra(a);
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		sa(a);
		ra(a);
	}
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rra(a);
}

void	small_sort(t_lst **a, t_lst **b, int size)
{
	if (size == 4)
	{
		pb(a, b);
		small_sort_three(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		pb(a, b);
		pb(a, b);
		small_sort_three(a);
		pa(a, b);
		if ((*a)->head > (*a)->next->next->next->head)
			ra(a);
		if ((*a)->head > (*a)->next->head)
			sa(a);
		pa(a, b);
		if ((*a)->head > (*a)->next->next->next->head)
			ra(a);
		if ((*a)->head > (*a)->next->head)
			sa(a);
	}
}

int	universal_sort(t_lst **a, t_lst **b)
{
	int		min;

	min = get_minimum(*a);
	pb(a, b);
	pb(a, b);
	if ((*b)->head < (*b)->next->head)
		sb(b);
	while (*a)
	{
		fill_target(a, b);
		fill_costs(*a, *b);
		move_the_cheapest(a, b);
	}
	while (*b)
		pa(a, b);
	while ((*a)->head != min)
	{
		if (get_direction(*a, min))
			ra(a);
		else
			rra(a);
	}
	return (0);
}
