/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:38:36 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/24 11:35:41 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_lstswap(t_list *old, t_list *new)
{
	void	*tmp;

	tmp = old->content;
	old->content = new->content;
	new->content = tmp;
}

// Swap the first two elements of the stack a
void	sa(t_list *a)
{
	if (ft_lstsize(a) < 2)
		return ;
	ft_lstswap(a, a->next);
	write(1, "sa", 2);
}

// Swap the first two elements of the stack b
void	sb(t_list *b)
{
	if (ft_lstsize(b) < 2)
		return ;
	ft_lstswap(b, b->next);
	write(1, "sb", 2);
}

// Swap the first two elements of the stack a and b
void	ss(t_list *a, t_list *b)
{
	if (ft_lstsize(a) < 2 || ft_lstsize(b) < 2)
		return ;
	ft_lstswap(a, a->next);
	ft_lstswap(b, b->next);
	write(1, "ss", 2);
}
