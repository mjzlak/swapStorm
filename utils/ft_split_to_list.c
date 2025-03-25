/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:46:22 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/25 14:05:19 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_split_to_list(char *str, char c, t_lst **a, int i)
{
	char	**array;
	int		is_overflow;
	int		value;
	t_lst	*new_node;

	is_overflow = 0;
	array = ft_split(str, c);
	if (!array)
		return (-1);
	i = 0;
	while (array[i])
	{
		value = ft_atoi(array[i], &is_overflow);
		new_node = ft_lstnew(value);
		if (!new_node)
		{
			free_array(array);
			ft_lstclear(a);
			return (-1);
		}
		ft_lstadd_back(a, new_node);
		i++;
	}
	free_array(array);
	return (0);
}
