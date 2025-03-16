/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:31 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/16 22:55:58 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort_three(t_lst **a)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*a)->content;
	val2 = (*a)->next->content;
	val3 = (*a)->next->next->content;
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
		if ((*a)->content > (*a)->next->next->next->content)
			ra(a);
		pa(a, b);
		if ((*a)->content > (*a)->next->next->next->content)
			ra(a);
	}
}

/*static void 	universal_sort(t_lst **a, t_lst **b, int size)
{

}*/

/*static int	find_min_value(t_lst *a)
{
	int		min;
	t_lst	*tmp;

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

static int	find_index_of_min(t_lst *a, int min_value)
{
	int		index;
	t_lst	*tmp;

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

static void	reverse_or_rotate(t_lst **a, int mid, int index)
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

void	big_sort(t_lst **a, t_lst **b)
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
}*/

/*static int	find_max_bits(t_lst *a)
{
	int	max;
	int	bits;

	max = *(int *)a->content;
	while (a)
	{
		if (*(int *)a->content > max)
			max = *(int *)a->content;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}*/

/*void	big_sort(t_lst **a, t_lst **b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	size = ft_lstsize(*a);
	max_bits = find_max_bits(*a);

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		int initial_size = size; // On garde la taille initiale pour éviter de changer `size` durant la boucle
		while (j < initial_size) 
		{
			if (((*(int *)(*a)->content >> i) & 1) == 0)
				pb(a, b); // On pousse les 0 dans `b`
			else
				ra(a);  // On fait juste avancer les 1
			j++;
		}
		while (*b) 
			pa(a, b);  // On récupère tous les éléments dans `b` en respectant leur ordre
		i++;
	}
}*/

/*static int	find_max_index(t_lst *b)
{
	int		max;
	int		index;
	int		max_index;
	t_lst	*tmp;

	if (!b)
		return (-1);
	tmp = b;
	max = *(int *)b->content;
	index = 0;
	max_index = 0;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
		{
			max = *(int *)tmp->content;
			max_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (max_index);
}

void	big_sort(t_lst **a, t_lst **b, int size, int max_bits)
{
	int	i;
	int	j;
	int	initial_size;
	int	max_index;

	size = ft_lstsize(*a);
	max_bits = find_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		initial_size = size;
		while (j < initial_size) 
		{
			if (((*(int *)(*a)->content >> i) & 1) == 0)
			{
				pb(a, b);
				if (*b && (*b)->next && *(int *)(*b)->content > *(int *)(*b)->next->content)
					rb(b);
			}
			else
			{
				if (*b && (*b)->next)
					rr(a, b);
				else
					ra(a);
			}
			j++;
		}
		while (*b)
		{
			max_index = find_max_index(*b);
			if (max_index < ft_lstsize(*b) / 2)
				while (max_index-- > 0)
					rb(b);
			else
			{
				while (max_index++ < ft_lstsize(*b))
					rrb(b);
			}
			pa(a, b);
		}
		i++;
	}
}*/
