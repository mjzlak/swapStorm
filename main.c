/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/02/03 11:32:13 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	push_swap(t_list *a, t_list *b)
{
	int	size;

	(void)b;
	size = ft_lstsize(a);
	if (size == 1)
		return (0);
	if (size == 2 && (*(int *)a->content > *(int *)a->next->content))
		sa(a);
	if (size == 3)
		small_sort_three(&a);
	else if (size > 3 && size <= 5)
		small_sort(&a, &b, size);
	else
		big_sort(&a, &b, size);
	return (0);
}

static int	init_list(t_list **a, int argc, char **argv)
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
			ft_lstclear(a, free);
			return (-1);
		}
		*value_ptr = value;
		ft_lstadd_front(a, ft_lstnew(value_ptr));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (error_handler(NULL, 0, argc, argv) == -1)
		return (-1);
	a = NULL;
	b = NULL;
	if (argc == 2)
		if (ft_split_to_list(argv[1], ' ', &a) == -1)
			return (-1);
	if (init_list(&a, argc, argv) == -1)
		return (-1);
	while (!is_sorted(a))
		push_swap(a, b);
	ft_lstclear(&a, free);
	return (0);
}
