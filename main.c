/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:03:17 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/22 10:56:31 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	push_swap(t_list *a, t_list *b)
{
	t_list	*current;

	current = a;
	while (current)
	{
		printf("a[%d] = %d\n", i, *(int *)(current->content));
		current = current->next;
		i++;
	}
	// 1. Parsing
	// 2. Initialiser et remplir la pile a
	// 3. Appeler la logique de tri
	// 4. Afficher les instructions
	return (0);
}*/

int	main(int argc, char **argv)
{
	if (error_handler(NULL, 0, argc, argv) == -1)
		return (-1);
	return (0);
}
