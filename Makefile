# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:10:17 by jeseo             #+#    #+#              #
#    Updated: 2022/12/27 17:04:26 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	./push_swap
NAME_BONUS	=	./checker

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

INC			=	./push_swap.h
INC_BONUS	=	./push_swap.h

SRC		=	./main.c\
			./push_swap_utils.c\
			./ft_calloc.c\
			./ft_strjoin.c\
			./quick_sort_array.c\
			./quick_sort_deque.c\
			./deque_utils.c\
			./parsing_data.c\
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

SRC_BOUNS	=	./main_bonus.c\


OBJ		=	$(SRC:%.c=%.o)
OBJ_BONUS	=	$(SRC_BONUS:%.c=%.o)

RM		=	rm -f

all		:	$(NAME)

bonus	:	$(NAME_BONUS)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ)	:	$(SRC) $(INC)
	$(CC) $(CFLAGS) -c $^

$(NAME_BONUS)	:	$(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BONUS)

$(OBJ_BONUS)	:	$(SRC_BONUS) $(INC_BONUS)
	$(CC) $(CFLAGS) -c $^

clean	:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean	:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re		:	fclean all

.PHONY	:	all clean fclean re