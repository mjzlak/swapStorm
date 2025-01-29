/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:49 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/22 12:28:33 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	arg_has_only_digits(int ac, char **av)
{
	int	j;

	ac = ac - 1;
	while (ac > 1)
	{
		j = 0;
		while (av[ac][j])
		{
			if ((av[ac][j] == '-' && ft_isdigit(av[ac][j + 1]))
				|| ft_isdigit(av[ac][j]))
			{
				j++;
				continue ;
			}
			else if (((av[ac][j] != '-' && !ft_isdigit(av[ac][j + 1]))
				&& av[ac][j] != ' ' && (av[1][j] >= 9 && av[1][j] <= 13))
					|| !ft_isdigit(av[ac][j]))
				return (-1);
			else if (av[ac][j] == '-' && !ft_isdigit(av[ac][j + 1]))
				return (-1);
			j++;
		}
		ac--;
	}
	return (0);
}

static int	arg_has_no_duplicate(int i, int ac, char **av)
{
	int		j;
	int		tmp;

	while (i < ac)
	{
		tmp = ft_atoi(av[i]);
		j = i + 1;
		while (j < ac)
		{
			if (tmp == ft_atoi(av[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_handler(char **array, int size, int ac, char **av)
{
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		while (array[size])
			size++;
		if (arg_has_no_duplicate(0, size, array) == -1
			|| arg_has_only_digits(size, array) == -1)
		{
			free_array(array);
			write(2, "Error\n", 6);
			return (-1);
		}
		free_array(array);
	}
	else
	{
		array = av;
		if ((arg_has_no_duplicate(1, ac, av) == -1) || ac < 2
			|| arg_has_only_digits(ac, av))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	return (0);
}
