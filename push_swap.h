/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:15:35 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/22 10:28:27 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

/*typedef struct t_element
{
	int             value;
	struct t_element   *next;
}   t_element;*/

// operations.c

// ft_split_to_list.c
void	free_array(char **array);
void	ft_split_to_list(char *str, char c, t_list *a);

// error_handler.c
int		error_handler(char **array, int size, int ac, char **av);

// main.c
int		push_swap(int argc, char **argv);
int		main(int argc, char **argv);

#endif