/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:49 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/17 15:10:58 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
					continue;
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

static int	arg_has_no_duplicate(int ac, char **av)
{
	int	i;
	int tmp;

	i = 0;
	ac = ac - 1;
	while (ac > 1)
	{
		tmp = ft_atoi(av[ac]);
		while (i <= ac)
		{
			if (tmp == ft_atoi(av[i]))
				return (-1);
			i++;
		}
		ac--;
	}
	return (0);
}

int	error_handler(int argc, char **argv)
{
	if ((argc < 2) || (arg_has_only_digits(argc, argv) == -1))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (arg_has_no_duplicate(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}
