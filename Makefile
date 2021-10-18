# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 11:23:22 by ogarthar          #+#    #+#              #
#    Updated: 2021/09/17 17:34:24 by ogarthar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

LIST =		main.c\
			push_swap.c\
			create_stack.c\
			actions.c\
			actions2.c\
			actions3.c\
			sort_small_stack.c\
			sort_big_stack.c\
			rotate_big_stack.c\
			utils.c

LIST_B =	push_swap.c\
			create_stack.c\
			actions.c\
			actions2.c\
			actions3.c\
			sort_small_stack.c\
			sort_big_stack.c\
			rotate_big_stack.c\
			utils.c\
			checker.c\
			get_next_line.c\
			get_next_line_utils.c


VPATH = src:

OBJ = $(patsubst %.c,%.o,$(LIST))

OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

HEADER = $(patsubst %.c,%.d,$(LIST))

HEADER_B = $(patsubst %.c,%.d,$(LIST_B))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -MD

all : $(NAME)

bonus: $(NAME) $(NAME_B)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_B):		$(OBJ_B)
		$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean :
	@rm -f $(OBJ) $(OBJ_B) $(HEADER) $(HEADER_B)

fclean : clean
	@rm -f $(NAME) $(NAME_B)

re : fclean all

-include $(HEADER)
-include $(HEADER_B)

.PHONY : all clean fclean re
