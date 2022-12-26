# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:10:17 by jeseo             #+#    #+#              #
#    Updated: 2022/12/26 21:51:01 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./push_swap

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

INC		=	./push_swap.h

SRC		=	./main.c\
			./push_swap_utils.c\
			./ft_calloc.c\
			./ft_strjoin.c\
			./quick_sort_array.c\
			./quick_sort_deque.c\
			./deque_utils.c\
			./argument_to_array.c\
			./argument_error.c\
			./a_to_b.c\
			./b_to_a.c\
			./range_three_arrange_a.c\
			./range_three_arrange_b.c\
			./total_range_less_than_five.c\
			./push.c\
			./swap.c\
			./reverse.c\
			./reverse_reverse.c\

OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ)	:	$(SRC) $(INC)
	$(CC) $(CFLAGS) -c $^

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re