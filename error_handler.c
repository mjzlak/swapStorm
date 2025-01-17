/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:19:49 by mloeffer          #+#    #+#             */
/*   Updated: 2025/01/17 09:46:16 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_is_only_digits_for_one_arg(int argc, char **argv)
{
	int	j;

	j = 0;
	if (argc == 2)
	{
		while (argv[1][j])
		{
			if (!ft_isdigit(argv[1][j]) && argv[1][j] != ' '
			&& (argv[1][j] >= 9 && argv[1][j] <= 13 && argv[1][j] != '-'))
				return (-1);
			if (argv[1][j] == '-' && !ft_isdigit(argv[1][j + 1]))
				return (-1);
			j++;
		}
	}
	return (0);
}

static int	check_is_only_digits_for_multiple_arg(int ac, char **av)
{
	int	j;

	j = 0;
	if (ac > 1)
	{
		while (--ac)
		{
			j = 0;
			while (av[ac][j])
			{
				if (!ft_isdigit(av[ac][j]) && av[ac][j] != ' '
				&& (av[ac][j] >= 9 && av[ac][j] <= 13 && av[ac][j] != '-'))
					return (-1);
				if (av[ac][j] == '-' && !ft_isdigit(av[ac][j + 1]))
					return (-1);
				j++;
			}
		}
	}
	return (0);
}

static int	check_duplicate_for_one_arg(char *arg, int count, int i, int *nums)
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

int	error_handler(int argc, char **argv)
{
	int	count;
	int	i;
	int	*nums;

	count = 0;
	i = -1;
	nums = NULL;
	if (argc < 2)
		return (-1);
	if (check_is_only_digits_for_one_arg(argc, argv) == -1)
		return (-1);
	if (check_is_only_digits_for_multiple_arg(argc, argv) == -1)
		return (-1);
	if (check_duplicate_for_one_arg(argv[1], count, i, nums) == -1)
	{
		free(nums);
		return (-1);
	}
	return (0);
}
