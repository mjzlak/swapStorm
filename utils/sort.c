/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:31 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/29 13:44:33 by mloeffer         ###   ########.fr       */
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
		if (*(int *)(*b)->content > *(int *)(*b)->next->content)
			sb(*b);
		small_sort_three(a);
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			sa(*a);
		pa(a, b);
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			sa(*a);
		pa(a, b);
	}
}

static t_list	*ft_lstsecondlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	turk_sort(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	while (*(int *)(*a)->content < *(int *)(*a)->next->content)
	{
		i++;
		pb(a, b);
		if (*(int *)(*b)->content < *(int *)(*b)->next->content && i > 2
			&& *(int *)(*b)->content < *(int *)(*b)->next->next->content)
			rb(b);
		else if (*(int *)(*b)->content < *(int *)(*b)->next->content && i > 2
			&& *(int *)(*b)->content > *(int *)(*b)->next->next->content)
			sb(*b);
		if (ft_lstlast(*b) < ft_lstsecondlast(*b))
		{
			rrb(b);
			rrb(b);
			sb(*b);
			rb(b);
			rb(b);
		}
	}
	while ((*a)->next)
		turk_sort(&(*a)->next, b, size);
	while ((*b)->next)
		pa(a, b);
}
