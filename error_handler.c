/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:49 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/17 12:40:14 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_is_only_digits_for_one_arg(char **argv)
{
	int	j;

	j = 0;
	while (argv[1][j])
	{
		while (argv[1][j] == ' ' || (argv[1][j] >= 9 && argv[1][j] <= 13))
			j++;
		if (argv[1][j] == '-' && !ft_isdigit(argv[1][j + 1]))
			return (-1);
		else if (argv[1][j] != '-' && !ft_isdigit(argv[1][j + 1]))
			return (-1);
		else if ((argv[1][j] == '-'
			&& ft_isdigit(argv[1][j + 1])) || ft_isdigit(argv[1][j]))
			j++;
		j++;
	}
	return (0);
}

static int	check_is_only_digits_for_multiple_arg(int ac, char **av)
{
	int	j;

	ac = ac - 1;
	while (ac > 1)
	{
		j = 0;
		while (av[ac][j])
		{
			if ((av[ac][j] == '-'
				&& ft_isdigit(av[ac][j + 1])) || ft_isdigit(av[ac][j]))
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

static int	check_dup_for_one_arg(char *arg, int count, int i, int *nums)
{
	char	**tokens;
	int		j;

	tokens = ft_split(arg, ' ');
	while (tokens[count])
		count++;
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (-1);
	while (++i < count)
		nums[i] = ft_atoi(tokens[i]);
	i = -1;
	while (++i < count - 1)
	{
		j = i;
		while (++j < count)
		{
			if (nums[i] == nums[j])
			{
				free_array(tokens);
				return (-1);
			}
		}
	}
	free_array(tokens);
	return (0);
}

/*static int	check_dup_for_more_arg(int ac, char **av, int count, int i, int *nums)
{
	char	**tokens;
	int		j;

	while (ac > 1)
	{
		//count = 0;
		tokens = ft_split(av[ac], ' ');
		while (tokens[count])
			count++;
		nums = malloc(sizeof(int) * count);
		if (!nums)
			return (-1);
		while (++i < count)
			nums[i] = ft_atoi(tokens[i]);
		i = -1;
		while (++i < count - 1)
		{
			j = i;
			while (++j < count)
			{
				if (nums[i] == nums[j])
				{
					free_array(tokens);
					return (-1);
				}
			}
		}
		free_array(tokens);
		ac--;
	}
	return (0);
}*/

int	error_handler(int argc, char **argv)
{
	int	size;
	int	i;
	int	*nb;

	size = 0;
	i = -1;
	nb = NULL;
	if ((argc < 2) || ((argc == 2)
	&& (check_is_only_digits_for_one_arg(argv) == -1)) || ((argc > 2)
	&& (check_is_only_digits_for_multiple_arg(argc, argv) == -1)))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if ((argc == 2) && (check_dup_for_one_arg(argv[1], size, i, nb) == -1))
	{
		free(nb);
		write(2, "Error\n", 6);
		return (-1);
	}
	if (argc > 2)
	// && (check_dup_for_more_arg(argc, argv, size, i, nb) == -1))
	{
		return (0);
		/*free(nb);
		write(2, "Error\n", 6);
		return (-1);*/
	}
	return (0);
}
