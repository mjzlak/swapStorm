/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:15:35 by mjzlak            #+#    #+#             */
/*   Updated: 2025/01/22 13:56:06 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

// operations.c

// ft_split_to_list.c
void	free_array(char **array);
int		ft_split_to_list(char *str, char c, t_list **a);

// error_handler.c
int		error_handler(char **array, int size, int ac, char **av);

// main.c
int		push_swap(t_list *a, t_list *b);
int		main(int argc, char **argv);

#endif
