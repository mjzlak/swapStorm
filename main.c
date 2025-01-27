/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/27 13:59:49 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	print_list(t_list *a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = a;
	while (tmp)
	{
		printf("\n[%d] = %d\n", i, *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
}*/

static void	small_sort_three(t_list **a)
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
		write(1, " ", 1);
		rra(a);
	}
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		ra(a);
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		sa(*a);
		write(1, " ", 1);
		ra(a);
	}
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rra(a);
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
	else if (size == 3)
		small_sort_three(&a);
/*	else if (size <= 5)
		small_sort(&a, &b, size);
	else
		radix_sort(&a, &b, size);*/
	return (0);
}

static int	init_list(t_list *a, t_list *b, int argc, char **argv)
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
			ft_lstclear(&a, free);
			return (-1);
		}
		*value_ptr = value;
		ft_lstadd_front(&a, ft_lstnew(value_ptr));
	}
	push_swap(a, b);
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
	{
		if (ft_split_to_list(argv[1], ' ', &a) == -1)
			return (-1);
	}
	else
	{
		if (init_list(a, b, argc, argv) == -1)
			return (-1);
	}
	ft_lstclear(&a, free);
	return (0);
}
