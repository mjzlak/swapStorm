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
		pa(a, b);
		if ((*a)->head > (*a)->next->next->next->head)
			ra(a);
	}
}
static void	print_lst(t_lst *lst, char *name)
{
	printf("-------------------------------------------------------\nList %s:\n", name);
	while (lst)
	{
		printf("content : %d\n", lst->head);
		/*printf("cost : %d\n", lst->cost);
		printf("target : %d\n", lst->target);*/
		lst = lst->next;
	}
	printf("-------------------------------------------------------\n");
}

int	universal_sort(t_lst **a, t_lst **b)
{
	int	min;

	min = get_minimum(*a);
	while (ft_lstsize(*a) > 3)
		pb(a, b);
	small_sort_three(a);
	print_lst(*a, "a before\n");
	while ((*a)->next)
	{
		fill_target(*a, *b);
		printf("filled target\n");
		fill_costs(*a, *b);
		printf("filled costs\n");
		move_the_cheapest(*a, *b);
		printf("moved the cheapest\n");
	}
	print_lst(*a, "a after fill and move\n");
	while (*b)
		pa(a, b);
	while ((*a)->head != min)
		if (get_direction(*a, min))
			ra(a);
		else
			rra(a);
	print_lst(*a, "a after final alignment\n");
	return (0);
}