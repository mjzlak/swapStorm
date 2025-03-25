/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/03/25 14:05:02 by mloeffer         ###   ########.fr       */
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
	if (size == 2)
		sa(a);
	else if (size == 3)
		small_sort_three(a);
	else if (size > 3 && size < 6)
		small_sort(a, b, size);
	else
		universal_sort(a, b);
	return (0);
}

static int	init_list(t_lst **a, int argc, char **argv, int *is_overflow)
{
	int	value;
	int	*value_ptr;

	while (argc > 1)
	{
		argc--;
		value = ft_atoi(argv[argc], is_overflow);
		if (*is_overflow)
		{
			ft_lstclear(a);
			return (-1);
		}
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
	int		is_overflow;

	a = NULL;
	b = NULL;
	is_overflow = 0;
	if (error_handler(NULL, 0, argc, argv) == -1)
		return (-1);
	if (argc == 2)
		if (ft_split_to_list(argv[1], ' ', &a, 0) == -1)
			return (-1);
	if (init_list(&a, argc, argv, &is_overflow) == -1)
		return (-1);
	if (a != NULL)
		push_swap(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
