/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:15:35 by mjzlak            #+#    #+#             */
/*   Updated: 2025/03/25 20:04:33 by mloeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	int				head;
	int				cost;
	int				target;
	struct s_lst	*next;
}	t_lst;

// moves
void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **b);
void	rrr(t_lst **a, t_lst **b);

// lst_utils.c
t_lst	*ft_lstlast(t_lst *lst);
size_t	ft_lstsize(t_lst *lst);
void	ft_lstclear(t_lst **lst);
void	ft_lstdelone(t_lst *lst);
void	free_list(t_lst *lst);

// lst_init.c
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
t_lst	*ft_lstnew(int content);

// sort.c
void	small_sort_three(t_lst **a);
void	small_sort(t_lst **a, t_lst **b, int size);
int		universal_sort(t_lst **a, t_lst **b);

// cost_calculator.c
int		get_cost(int elem, int target, t_lst *a, t_lst *b);
int		get_target(t_lst **b, int elem);
int		get_maximum(t_lst *lst);
int		get_minimum(t_lst *lst);
int		get_cheapest_move(t_lst *a);

// do_and_move.c
void	fill_costs(t_lst *a, t_lst *b);
void	fill_target(t_lst **a, t_lst **b);
void	move_the_cheapest(t_lst **a, t_lst **b);
int		get_direction(t_lst *lst, int elem);

// ft_split_to_list.c
void	free_array(char **array);
int		ft_split_to_list(char *str, char c, t_lst **a, int i);

// error_handler.c
int		print_and_return_error(char *message, int return_value);
int		error_handler(char **array, int size, int ac, char **av);

// main.c
int		main(int argc, char **argv);

#endif
