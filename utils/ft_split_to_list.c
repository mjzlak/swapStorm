/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:46:22 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/22 13:55:16 by mloeffer         ###   ########.fr       */
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

int	ft_split_to_list(char *str, char c, t_list **a)
{
	char	**array;
	int		i;
	int		*value;

	array = ft_split(str, c);
	i = 0;
	while (array[i])
	{
		value = malloc(sizeof(int));
		if (!value)
		{
			free_array(array);
			ft_lstclear(a, free);
			return (-1);
		}
		*value = ft_atoi(array[i]);
		ft_lstadd_back(a, ft_lstnew(value));
		i++;
	}
	free_array(array);
	return (0);
}
