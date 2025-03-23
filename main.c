/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/03/23 21:09:02 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	is_sorted(t_lst *a)
{
	while (a && a->next)
	{
		if (a->head > a->next->head)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	push_swap(t_lst **a, t_lst **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(*a))
		return (0);
	if (size == 1)
		return (0);
	if (size == 2 && (*a)->head > (*a)->next->head)
		sa(a);
	else if (size == 3)
		small_sort_three(a);
	else if (size > 3 && size < 6)
		small_sort(a, b, size);
	else
		universal_sort(a, b);
	return (0);
}

static int	init_list(t_lst **a, int argc, char **argv)
{
	int	value;
	int	*value_ptr;

	while (argc > 1)
	{
		argc--;
		value = ft_atoi(argv[argc]);
		value_ptr = malloc(sizeof(int));
		if (!value_ptr)
		{
			ft_lstclear(a);
			return (-1);
		}
		*value_ptr = value;
		ft_lstadd_front(a, ft_lstnew(*value_ptr));
		free(value_ptr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;

	a = NULL;
	b = NULL;
	if (error_handler(NULL, 0, argc, argv) == -1)
		return (-1);
	if (argc == 2)
		if (ft_split_to_list(argv[1], ' ', &a) == -1)
			return (-1);
	if (init_list(&a, argc, argv) == -1)
		return (-1);
	push_swap(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
