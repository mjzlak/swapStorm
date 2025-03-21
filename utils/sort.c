/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:31 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/21 19:51:46mloeffer         ###   ########.fr       */
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
static void	print_lst(t_lst *lst, char *name)
{
	printf("-------------------------------------------------------\nList %s:\n", name);
	while (lst)
	{
		printf("content : %d\n", lst->content);
		/*printf("cost : %d\n", lst->cost);
		printf("target : %d\n", lst->target);*/
		lst = lst->next;
	}
	printf("-------------------------------------------------------\n");
}

int	universal_sort(t_lst **a, t_lst **b, int size, int pos)
{
	int		target;
	int		cost;
	int		min_pos;
    t_lst	*tmp;

	//print_lst(*a, "a before sort three");
    while (ft_lstsize(*a) > 3)
        pb(a, b);
    small_sort_three(a);
	//print_lst(*a, "a after sort three");
    while (*b)
    {
        target = get_target(*a, (*b)->content);
        cost = get_cost(*a, target);
        if (cost == -1)
            return (print_and_return_error("Error: Invalid cost calculation\n", -1));
        size = ft_lstsize(*a);
        pos = cost;
        if (pos <= size / 2)
            while (pos-- > 0)
                ra(a);
        else
            while (pos++ < size)
                rra(a);
        pa(a, b);
    }
	//print_lst(*a, "a after insertion");
    min_pos = 0;
	tmp = *a;
    while (tmp)
    {
        if (tmp->content == get_minimum(*a))
            break;
        min_pos++;
        tmp = tmp->next;
    }
    size = ft_lstsize(*a);
    if (min_pos <= size / 2)
        while (min_pos-- > 0)
            ra(a);
    else
        while (min_pos++ < size)
            rra(a);
	print_lst(*a, "a after final alignment");
    return (0);
}