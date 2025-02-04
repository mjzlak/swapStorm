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

void	small_sort(t_list **a, t_list **b, int size)
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
		if (*(int *)(*a)->content > *(int *)(*a)->next->next->next->content)
			ra(a);
		pa(a, b);
		if (*(int *)(*a)->content > *(int *)(*a)->next->next->next->content)
			ra(a);
	}
}

static int	find_min_value(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
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
	t_list	*tmp;

	if (!a)
		return (-1);
	tmp = a;
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

static void	reverse_or_rotate(t_list **a, int mid, int index)
{
	int	buf;

	if (index > mid)
	{
		buf = ft_lstsize(*a) - index;
		while (buf-- > 0)
			rra(a);
	}
	else
	{
		while (index-- > 0)
			ra(a);
	}
}

void	big_sort(t_list **a, t_list **b)
{
	int	min_value;
	int	index;
	int	mid;

	while (ft_lstsize(*a) > 0)
	{
		min_value = find_min_value(*a);
		index = find_index_of_min(*a, min_value);
		mid = ft_lstsize(*a) / 2;
		reverse_or_rotate(a, mid, index);
		pb(a, b);
	}
	while (ft_lstsize(*b) > 0)
		pa(a, b);
}
