/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:31 by mloeffer          #+#    #+#             */
/*   Updated: 2025/02/03 08:58:33 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort_three(t_list **a)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = *(int *)(*a)->content;
	val2 = *(int *)(*a)->next->content;
	val3 = *(int *)(*a)->next->next->content;
	if (val1 > val2 && val2 < val3 && val1 < val3)
		sa(*a);
	else if (val1 > val2 && val2 > val3)
	{
		sa(*a);
		rra(a);
	}
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		ra(a);
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		sa(*a);
		ra(a);
	}
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rra(a);
}

static int	find_min_value(t_list *a)
{
	int		min;
	t_list	*tmp = a;

	min = *(int *)a->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

static int	find_index_of_min(t_list *a, int min_value)
{
	int		index;
	t_list	*tmp = a;

	index = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == min_value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	big_sort(t_list **a, t_list **b)
{
	int	min_value;
	int	index;

	while (ft_lstsize(*a) > 0)
	{
		min_value = find_min_value(*a);
		if (find_index_of_min(*a, min_value))
			index = find_index_of_min(*a, min_value);
		while (index > 0)
		{
			ra(a);
			index--;
		}
		pb(a, b);
	}
	while (ft_lstsize(*b) > 0)
		pa(a, b);
}
