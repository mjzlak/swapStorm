/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:46:22 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/16 11:08:40 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(char **array)
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

void	ft_split_to_list(char *str, char c, t_list *a)
{
	char	**array;
	int		i;
	int		*value;

	array = ft_split(str, c);
	i = 0;
	value = NULL;
	while (array[i])
	{
		*value = ft_atoi(array[i]);
		ft_lstadd_front(&a, ft_lstnew(value));
		i++;
	}
	free_array(array);
}
