# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mloeffer <mloeffer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 08:27:01 by mjzlak            #+#    #+#              #
#    Updated: 2025/03/16 22:55:33 by mloeffer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c \
	   utils/error_handler.c \
	   utils/ft_split_to_list.c \
	   utils/sort.c \
	   utils/lst_utils.c \
	   moves/swap.c \
	   moves/push.c \
	   moves/rotate.c \
	   moves/reverse_rotate.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY : all
all: $(LIBFT) $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

.PHONY : clean
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY : fclean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

.PHONY : re
re: fclean all
