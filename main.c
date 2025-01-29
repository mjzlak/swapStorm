/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/28 13:53:14 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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
		turk_sort(&a, &b, size);
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
