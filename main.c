/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/24 11:47:39 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *a)
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

int	push_swap(t_list *a, t_list *b)
{
	int	values[5];
	int	i;
	int	*value_ptr;

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	values[3] = 4;
	values[4] = 5;
	i = 0;
	while (i < 5)
	{
		*value_ptr = malloc(sizeof(int));
		if (!value_ptr)
		{
			ft_lstclear(&b, free);
			return (-1);
		}
		*value_ptr = values[i];
		ft_lstadd_back(&b, ft_lstnew(value_ptr));
		i++;
	}
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\nsa\n\n");
	sa(a);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nsb\n\n");
	sb(b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nss\n\n");
	ss(a, b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\npa\n\n");
	pa(&a, &b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\npb\n\n");
	pb(&a, &b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nra\n\n");
	ra(&a);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nrb\n\n");
	rb(&b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nrr\n\n");
	rr(&a, &b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nrra\n\n");
	rra(&a);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nrrb\n\n");
	rrb(&b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	printf("\n\nrrr\n\n");
	rrr(&a, &b);
	printf("list a\n");
	print_list(a);
	printf("list b\n");
	print_list(b);
	return (0);
}

int	init_list(t_list *a, t_list *b, int argc, char **argv)
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
