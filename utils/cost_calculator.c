/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:48:32 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/21 20:47:50 by mloeffer         ###   ########.fr       */
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

int	get_target(t_lst *a, int elem)
{
    int		min;
    int		max;
    int		candidate;
    t_lst	*tmp;

    min = get_minimum(a);
    max = get_maximum(a);
    if (elem < min || elem > max)
        return (min);
    candidate = max;
    tmp = a;
    while (tmp)
    {
        if (tmp->content >= elem && tmp->content < candidate)
            candidate = tmp->content;
        tmp = tmp->next;
    }
    return (candidate);
}

int	get_cost(t_lst *lst, int target)
{
    int	cost;

    cost = 0;
    while (lst)
    {
        if (lst->content == target)
            return (cost);
        lst = lst->next;
        cost++;
    }
    return (-1);
}