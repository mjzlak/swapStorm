/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:38:36 by mjzlak            #+#    #+#             */
/*   Updated: 2025/03/22 14:33:01 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_lstswap(t_lst *old, t_lst *new)
{
	int	tmp;

	tmp = old->head;
	old->head = new->head;
	new->head = tmp;
}

// Swap the first two elements of the stack a
void	sa(t_lst **a)
{
	if (ft_lstsize(*a) < 2)
		return ;
	ft_lstswap(*a, (*a)->next);
	write(1, "sa\n", 3);
}

// Swap the first two elements of the stack b
void	sb(t_lst **b)
{
	if (ft_lstsize(*b) < 2)
		return ;
	ft_lstswap(*b, (*b)->next);
	write(1, "sb\n", 3);
}

// Swap the first two elements of the stack a and b
void	ss(t_lst **a, t_lst **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	ft_lstswap(*a, (*a)->next);
	ft_lstswap(*b, (*b)->next);
	write(1, "ss\n", 3);
}
