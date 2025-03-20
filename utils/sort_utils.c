/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:48:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/20 03:51:33 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_maximum(t_lst *lst)
{
	int	max;

	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	get_minimum(t_lst *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}


int get_cost(t_lst *lst, int target)
{
    int cost = 0;

    while (lst)
    {
        if (lst->content == target)
            return cost;
        lst = lst->next;
        cost++;
    }
    return (-1);
}

int get_target(t_lst *b, int elem)
{
	t_lst	*tmp;

	tmp = b;
	while (tmp && tmp->next)
	{
		if (tmp->content > elem && tmp->next->content < elem)
			return (tmp->next->content);
		tmp = tmp->next;
	}
	return (get_maximum(b));
}