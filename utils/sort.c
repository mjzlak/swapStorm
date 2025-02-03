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

/*static t_list	*ft_lstsecondlast(t_list *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}*/

static void	print_list(t_list *a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		printf("[%d] = %d\n", i, *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
}

void	big_sort(t_list **a, t_list **b, int size)
{
	int	i;

	i = 0;
	while ((*a) && i < size)
	{
		pb(a, b);
		i++;
		if (*b && (*b)->next)
		{
			if ((*b)->next && (*b)->next->next && *(int *)(*b)->content
				< *(int *)(*b)->next->content && *(int *)(*b)->content
				< *(int *)(*b)->next->next->content)
				rb(b);
			else if ((*b)->next && (*b)->next->next && *(int *)(*b)->content
					< *(int *)(*b)->next->content && *(int *)(*b)->content
					> *(int *)(*b)->next->next->content)
				sb(*b);
		}
	}
	__builtin_printf("(*b)->content : %i\n\n", *(int *)(*b)->content);
	while ((*b))
		pa(a, b);
	print_list(*a);
}
