# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 19:21:13 by tigerber          #+#    #+#              #
#    Updated: 2021/08/13 22:48:37 by tigerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  srcs/push_swap.c			\
		srcs/ft_parsing.c			\
		srcs/utils_lst.c			\
		srcs/utils_push_swap.c		\
		srcs/utils_libft.c			\
		srcs/ft_sort_tab.c			\
		srcs/function_swap_push.c	\
		srcs/function_rotate.c 		\
		srcs/function_rev_rotate.c 	\
		srcs/ft_big_sort.c			\
		srcs/ft_small_sort.c		

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include/

HEADER = -I ./includes/

OBJ = $(SRCS:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

all: $(NAME)

%.o%.c:
	$(CC) -c $(CFLAGS) -I $(HEADER) $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re