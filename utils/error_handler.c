/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:49 by mloeffer          #+#    #+#             */
/*   Updated: 2025/03/24 18:59:31 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_and_return_error(char *message, int return_value)
{
	write(2, message, ft_strlen(message));
	return (return_value);
}
static int	arg_has_only_digits(int ac, char **av)
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
				if (!ft_isdigit(av[i][j + 1]))
					return (-1);
			}
			else if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
				&& (av[i][j] < 9 || av[i][j] > 13))
				return (-1);
			j++;
		}
		i--;
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
    if (ac == 1)
		return (0);
    if (ac == 2)
    {
        array = ft_split(av[1], ' ');
        if (!array)
            return (print_and_return_error("Error\n", -1));
        while (array[size])
            size++;
        if (size == 0 || arg_has_no_duplicate(0, size, array) == -1
            || arg_has_only_digits(size, array) == -1)
        {
            free_array(array);
            return (print_and_return_error("Error\n", -1));
        }
        free_array(array);
        return (0);
    }
    if ((arg_has_no_duplicate(1, ac, av) == -1)
        || arg_has_only_digits(ac, av) == -1 || av[1][0] == '\0')
        return (print_and_return_error("Error\n", -1));
    return (0);
}
