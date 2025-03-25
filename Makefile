# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 08:27:01 by mjzlak            #+#    #+#              #
#    Updated: 2025/03/25 11:11:38 by mloeffer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -Iinclude

SRCS = main.c \
	   utils/error_handler.c \
	   utils/ft_split_to_list.c \
	   utils/sort.c \
	   utils/cost_calculator.c \
	   utils/do_and_move.c \
	   utils/lst_utils.c \
	   utils/lst_init.c \
	   moves/swap.c \
	   moves/push.c \
	   moves/rotate.c \
	   moves/reverse_rotate.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY : all
all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

-include $(DEPS)

.PHONY : clean
clean:
	rm -f $(OBJS) $(DEPS)
	make -C $(LIBFT_DIR) clean

.PHONY : fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

.PHONY : re
re: fclean all
