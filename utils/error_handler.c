/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:49 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/25 17:54:58 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_and_return_error(char *message, int return_value)
{
	write(2, message, ft_strlen(message));
	return (return_value);
}

static int	args_has_only_digits(int ac, char **av, int overflow)
{
	int	i;
	int	j;

	i = ac - 1;
	while (i > 0)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (!av[i][j + 1] || !ft_isdigit(av[i][j + 1])
					|| (j > 0 && av[i][j - 1] != ' '))
					return (-1);
			}
			else if (!ft_isdigit(av[i][j]) && !is_skippable(av[i][j]))
				return (-1);
			j++;
		}
		ft_atoi(av[i], &overflow);
		if (overflow)
			return (-1);
		i--;
	}
	return (0);
}

static int	args_has_no_duplicate(int i, int ac, char **av, int overflow)
{
	int		j;
	int		tmp;

	while (i < ac)
	{
		tmp = ft_atoi(av[i], &overflow);
		if (overflow)
			return (-1);
		j = i + 1;
		while (j < ac)
		{
			if (tmp == ft_atoi(av[j], &overflow))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_has_only_digits(int ac, char **av, int overflow)
{
	int	i;
	int	j;

	i = ac - 1;
	while (i >= 0)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (!av[i][j + 1] || !ft_isdigit(av[i][j + 1])
					|| (j > 0 && av[i][j - 1] != ' '))
					return (-1);
			}
			else if (!ft_isdigit(av[i][j]) && !is_skippable(av[i][j]))
				return (-1);
			j++;
		}
		ft_atoi(av[i], &overflow);
		if (overflow)
			return (-1);
		i--;
	}
	return (0);
}

int	error_handler(char **array, int size, int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		if (!array)
			return (print_and_return_error("Error\n", -1));
		while (array[size])
			size++;
		if (size == 0
			|| (size == 1 && arg_has_only_digits(size, array, 0) == -1)
			|| (size == 1 && args_has_no_duplicate(0, size, array, 0) == -1)
			|| args_has_no_duplicate(0, size, array, 0) == -1
			|| arg_has_only_digits(size, array, 0) == -1)
		{
			free_array(array);
			return (print_and_return_error("Error\n", -1));
		}
		free_array(array);
		return (0);
	}
	if ((args_has_no_duplicate(1, ac, av, 0) == -1)
		|| args_has_only_digits(ac, av, 0) == -1 || av[1][0] == '\0')
		return (print_and_return_error("Error\n", -1));
	return (0);
}
